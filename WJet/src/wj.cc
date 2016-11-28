// main31.cc is a part of the PYTHIA event generator.
// Copyright (C) 2014 Richard Corke, Torbjorn Sjostrand.
// PYTHIA is licenced under the GNU GPL version 2, see COPYING for details.
// Please respect the MCnet Guidelines, see GUIDELINES for details.

#include "Pythia8/Pythia.h"
#include "fastjet/ClusterSequence.hh"
#include "Pythia8Plugins/JetMatching.h"
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TRandom3.h"
#include "TParameter.h"

using namespace Pythia8;

double get_dR(Vec4 mom, fastjet::PseudoJet& jet){
  double p_phi = mom.phi();
  double j_phi = jet.phi_std();
  double dPhi  = abs(p_phi - j_phi) < TMath::Pi() ? abs(p_phi - j_phi) : 2*TMath::Pi() - abs(p_phi - j_phi);
  double dEta  = mom.eta() - jet.eta();
  double dR    = sqrt(dPhi * dPhi + dEta * dEta);
  //cout<<"phi1: "<<p_phi<<" phi2: "<<j_phi<<" eta1: "<<mom.eta()<<" eta2: "<<jet.eta()<<" dPhi: "<<dPhi<<" dEta: "<<dEta<<" dR: "<<dR<<endl;
  
  return dR;

}

void getVals(Vec4 mom, vector<double>& vals, bool rap = false){
  //vector<double> vals(7, 0.0);
  vals[0] = mom.px();
  vals[1] = mom.py();
  vals[2] = mom.pz();
  vals[3] = mom.pT();
  vals[4] = mom.pAbs();
  vals[5] = mom.phi();
  if (rap){
    vals[6] = mom.rap();
  }
  else vals[6] = mom.eta();
  vals[7] = mom.mCalc();
  //return vals;
}
void getVals(fastjet::PseudoJet& jet, vector<double>& vals){
  //vector<double> vals(9, 0.0);
  vals[0] = jet.px();
  vals[1] = jet.py();
  vals[2] = jet.pz();
  vals[3] = sqrt(jet.px() * jet.px() + jet.py() * jet.py());
  vals[4] = sqrt(jet.pt() * jet.pt() + jet.pz() * jet.pz());
  vals[5] = jet.phi_std();
  vals[6] = jet.eta();
  vals[7] = jet.e();
  vals[8] = jet.Et();
  vals[9] = jet.m();


  //return vals;
}
void getVals(Particle& part, vector<double>& vals, bool rap = false){
  getVals(part.p(), vals, rap);
}


bool fromPart(Event &event, Particle part, int ancestor){
  bool desc = false;
  int motheridx = part.mother1();
  while (motheridx > 0){
    if (abs(event[motheridx].id()) == ancestor) desc = true;
    motheridx = event[motheridx].mother1();
  }
  return desc;
}


bool isFinalState(Particle part){
  if(part.daughter1() > 0) return false;
  return true;
}

//==========================================================================

// Use userhooks to veto PYTHIA emissions above the POWHEG scale.

class PowhegHooks : public UserHooks {

public:

  // Constructor and destructor.
   PowhegHooks(int nFinalIn, int vetoModeIn, int vetoCountIn,
               int pThardModeIn, int pTemtModeIn, int emittedModeIn,
               int pTdefModeIn, int MPIvetoModeIn) : nFinal(nFinalIn),
               vetoMode(vetoModeIn), vetoCount(vetoCountIn),
               pThardMode(pThardModeIn), pTemtMode(pTemtModeIn),
               emittedMode(emittedModeIn), pTdefMode(pTdefModeIn),
               MPIvetoMode(MPIvetoModeIn) {};
  ~PowhegHooks() {}

//--------------------------------------------------------------------------

  // Routines to calculate the pT (according to pTdefMode) in a splitting:
  //   ISR: i (radiator after)  -> j (emitted after) k (radiator before)
  //   FSR: i (radiator before) -> j (emitted after) k (radiator after)
  // For the Pythia pT definition, a recoiler (after) must be specified.

  // Compute the Pythia pT separation. Based on pTLund function in History.cc
  double pTpythia(const Event &e, int RadAfterBranch, int EmtAfterBranch,
                  int RecAfterBranch, bool FSR) {

    // Convenient shorthands for later
    Vec4 radVec = e[RadAfterBranch].p();
    Vec4 emtVec = e[EmtAfterBranch].p();
    Vec4 recVec = e[RecAfterBranch].p();
    int  radID  = e[RadAfterBranch].id();

    // Calculate virtuality of splitting
    double sign = (FSR) ? 1. : -1.;
    Vec4 Q(radVec + sign * emtVec);
    double Qsq = sign * Q.m2Calc();

    // Mass term of radiator
    double m2Rad = (abs(radID) >= 4 && abs(radID) < 7) ?
                   pow2(particleDataPtr->m0(radID)) : 0.;

    // z values for FSR and ISR
    double z, pTnow;
    if (FSR) {
      // Construct 2 -> 3 variables
      Vec4 sum = radVec + recVec + emtVec;
      double m2Dip = sum.m2Calc();
      double x1 = 2. * (sum * radVec) / m2Dip;
      double x3 = 2. * (sum * emtVec) / m2Dip;
      z     = x1 / (x1 + x3);
      pTnow = z * (1. - z);

    } else {
      // Construct dipoles before/after splitting
      Vec4 qBR(radVec - emtVec + recVec);
      Vec4 qAR(radVec + recVec);
      z     = qBR.m2Calc() / qAR.m2Calc();
      pTnow = (1. - z);
    }

    // Virtuality with correct sign
    pTnow *= (Qsq - sign * m2Rad);

    // Can get negative pT for massive splittings
    if (pTnow < 0.) {
      cout << "Warning: pTpythia was negative" << endl;
      return -1.;
    }

#ifdef DBGOUTPUT
    cout << "pTpythia: rad = " << RadAfterBranch << ", emt = "
         << EmtAfterBranch << ", rec = " << RecAfterBranch
         << ", pTnow = " << sqrt(pTnow) << endl;
#endif

    // Return pT
    return sqrt(pTnow);
  }

  // Compute the POWHEG pT separation between i and j
  double pTpowheg(const Event &e, int i, int j, bool FSR) {

    // pT value for FSR and ISR
    double pTnow = 0.;
    if (FSR) {
      // POWHEG d_ij (in CM frame). Note that the incoming beams have not
      // been updated in the parton systems pointer yet (i.e. prior to any
      // potential recoil).
      int iInA = partonSystemsPtr->getInA(0);
      int iInB = partonSystemsPtr->getInB(0);
      double betaZ = - ( e[iInA].pz() + e[iInB].pz() ) /
                       ( e[iInA].e()  + e[iInB].e()  );
      Vec4 iVecBst(e[i].p()), jVecBst(e[j].p());
      iVecBst.bst(0., 0., betaZ);
      jVecBst.bst(0., 0., betaZ);
      pTnow = sqrt( (iVecBst + jVecBst).m2Calc() *
                    iVecBst.e() * jVecBst.e() /
                    pow2(iVecBst.e() + jVecBst.e()) );

    } else {
      // POWHEG pT_ISR is just kinematic pT
      pTnow = e[j].pT();
    }

    // Check result
    if (pTnow < 0.) {
      cout << "Warning: pTpowheg was negative" << endl;
      return -1.;
    }

#ifdef DBGOUTPUT
    cout << "pTpowheg: i = " << i << ", j = " << j
         << ", pTnow = " << pTnow << endl;
#endif

    return pTnow;
  }

  // Calculate pT for a splitting based on pTdefMode.
  // If j is -1, all final-state partons are tried.
  // If i, k, r and xSR are -1, then all incoming and outgoing
  // partons are tried.
  // xSR set to 0 means ISR, while xSR set to 1 means FSR
  double pTcalc(const Event &e, int i, int j, int k, int r, int xSRin) {

    // Loop over ISR and FSR if necessary
    double pTemt = -1., pTnow;
    int xSR1 = (xSRin == -1) ? 0 : xSRin;
    int xSR2 = (xSRin == -1) ? 2 : xSRin + 1;
    for (int xSR = xSR1; xSR < xSR2; xSR++) {
      // FSR flag
      bool FSR = (xSR == 0) ? false : true;

      // If all necessary arguments have been given, then directly calculate.
      // POWHEG ISR and FSR, need i and j.
      if ((pTdefMode == 0 || pTdefMode == 1) && i > 0 && j > 0) {
        pTemt = pTpowheg(e, i, j, (pTdefMode == 0) ? false : FSR);

      // Pythia ISR, need i, j and r.
      } else if (!FSR && pTdefMode == 2 && i > 0 && j > 0 && r > 0) {
        pTemt = pTpythia(e, i, j, r, FSR);

      // Pythia FSR, need k, j and r.
      } else if (FSR && pTdefMode == 2 && j > 0 && k > 0 && r > 0) {
        pTemt = pTpythia(e, k, j, r, FSR);

      // Otherwise need to try all possible combintations.
      } else {
        // Start by finding incoming legs to the hard system after
        // branching (radiator after branching, i for ISR).
        // Use partonSystemsPtr to find incoming just prior to the
        // branching and track mothers.
        int iInA = partonSystemsPtr->getInA(0);
        int iInB = partonSystemsPtr->getInB(0);
        while (e[iInA].mother1() != 1) { iInA = e[iInA].mother1(); }
        while (e[iInB].mother1() != 2) { iInB = e[iInB].mother1(); }

        // If we do not have j, then try all final-state partons
        int jNow = (j > 0) ? j : 0;
        int jMax = (j > 0) ? j + 1 : e.size();
        for (; jNow < jMax; jNow++) {

          // Final-state and coloured jNow only
          if (!e[jNow].isFinal() || e[jNow].colType() == 0) continue;

          // POWHEG
          if (pTdefMode == 0 || pTdefMode == 1) {

            // ISR - only done once as just kinematical pT
            if (!FSR) {
              pTnow = pTpowheg(e, iInA, jNow, (pTdefMode == 0) ? false : FSR);
              if (pTnow > 0.) pTemt = (pTemt < 0) ? pTnow : min(pTemt, pTnow);
  
              // FSR - try all outgoing partons from system before branching
              // as i. Note that for the hard system, there is no
              // "before branching" information.
              } else {
    
                int outSize = partonSystemsPtr->sizeOut(0);
                for (int iMem = 0; iMem < outSize; iMem++) {
                  int iNow = partonSystemsPtr->getOut(0, iMem);

                  // Coloured only, i != jNow and no carbon copies
                  if (iNow == jNow || e[iNow].colType() == 0) continue;
                  if (jNow == e[iNow].daughter1()
                    && jNow == e[iNow].daughter2()) continue;

                  pTnow = pTpowheg(e, iNow, jNow, (pTdefMode == 0)
                    ? false : FSR);
                  if (pTnow > 0.) pTemt = (pTemt < 0)
                    ? pTnow : min(pTemt, pTnow);
                } // for (iMem)
  
              } // if (!FSR)
  
          // Pythia
          } else if (pTdefMode == 2) {
  
            // ISR - other incoming as recoiler
            if (!FSR) {
              pTnow = pTpythia(e, iInA, jNow, iInB, FSR);
              if (pTnow > 0.) pTemt = (pTemt < 0) ? pTnow : min(pTemt, pTnow);
              pTnow = pTpythia(e, iInB, jNow, iInA, FSR);
              if (pTnow > 0.) pTemt = (pTemt < 0) ? pTnow : min(pTemt, pTnow);
  
            // FSR - try all final-state coloured partons as radiator
            //       after emission (k).
            } else {
              for (int kNow = 0; kNow < e.size(); kNow++) {
                if (kNow == jNow || !e[kNow].isFinal() ||
                    e[kNow].colType() == 0) continue;
  
                // For this kNow, need to have a recoiler.
                // Try two incoming.
                pTnow = pTpythia(e, kNow, jNow, iInA, FSR);
                if (pTnow > 0.) pTemt = (pTemt < 0)
                  ? pTnow : min(pTemt, pTnow);
                pTnow = pTpythia(e, kNow, jNow, iInB, FSR);
                if (pTnow > 0.) pTemt = (pTemt < 0)
                  ? pTnow : min(pTemt, pTnow);

                // Try all other outgoing.
                for (int rNow = 0; rNow < e.size(); rNow++) {
                  if (rNow == kNow || rNow == jNow ||
                      !e[rNow].isFinal() || e[rNow].colType() == 0) continue;
                  pTnow = pTpythia(e, kNow, jNow, rNow, FSR);
                  if (pTnow > 0.) pTemt = (pTemt < 0)
                    ? pTnow : min(pTemt, pTnow);
                } // for (rNow)
  
              } // for (kNow)
            } // if (!FSR)
          } // if (pTdefMode)
        } // for (j)
      }
    } // for (xSR)

#ifdef DBGOUTPUT
    cout << "pTcalc: i = " << i << ", j = " << j << ", k = " << k
         << ", r = " << r << ", xSR = " << xSRin
         << ", pTemt = " << pTemt << endl;
#endif

    return pTemt;
  }

//--------------------------------------------------------------------------

  // Extraction of pThard based on the incoming event.
  // Assume that all the final-state particles are in a continuous block
  // at the end of the event and the final entry is the POWHEG emission.
  // If there is no POWHEG emission, then pThard is set to SCALUP.

  bool canVetoMPIStep()    { return true; }
  int  numberVetoMPIStep() { return 1; }
  bool doVetoMPIStep(int nMPI, const Event &e) {
    // Extra check on nMPI
    if (nMPI > 1) return false;

    // Find if there is a POWHEG emission. Go backwards through the
    // event record until there is a non-final particle. Also sum pT and
    // find pT_1 for possible MPI vetoing
    int    count = 0;
    double pT1 = 0., pTsum = 0.;
    for (int i = e.size() - 1; i > 0; i--) {
      if (e[i].isFinal()) {
	//cout<<e[i].id()<<endl;
        count++;
        pT1    = e[i].pT();
        pTsum += e[i].pT();
      } else break;
    }
    //cout<<"---------------"<<endl;
    // Extra check that we have the correct final state
    if (count != nFinal && count != nFinal + 1) {
      cout << "Error: wrong number of final state particles in event" << endl;
      //cout << "Comparing count of "<<count<<" to "<<nFinal<<endl;
      exit(1);
    }
    // Flag if POWHEG radiation present and index
    bool isEmt = (count == nFinal) ? false : true;
    int  iEmt  = (isEmt) ? e.size() - 1 : -1;

    // If there is no radiation or if pThardMode is 0 then set pThard = SCALUP.
    if (!isEmt || pThardMode == 0) {
      pThard = infoPtr->scalup();
      
    // If pThardMode is 1 then the pT of the POWHEG emission is checked against
    // all other incoming and outgoing partons, with the minimal value taken
    } else if (pThardMode == 1) {
      pThard = pTcalc(e, -1, iEmt, -1, -1, -1);

    // If pThardMode is 2, then the pT of all final-state partons is checked
    // against all other incoming and outgoing partons, with the minimal value
    // taken
    } else if (pThardMode == 2) {
      pThard = pTcalc(e, -1, -1, -1, -1, -1);
    }

    // Find MPI veto pT if necessary
    if (MPIvetoMode == 1) {
      pTMPI = (isEmt) ? pTsum / 2. : pT1;
    }

#ifdef DBGOUTPUT
    cout << "doVetoMPIStep: Qfac = " << infoPtr->scalup()
         << ", pThard = " << pThard << endl << endl;
#endif

    // Initialise other variables
    accepted   = false;
    nAcceptSeq = nISRveto = nFSRveto = 0;

    // Do not veto the event
    return false;
  }

//--------------------------------------------------------------------------

  // ISR veto

  bool canVetoISREmission() { return (vetoMode == 0) ? false : true; }
  bool doVetoISREmission(int, const Event &e, int iSys) {
    // Must be radiation from the hard system
    if (iSys != 0) return false;

    // If we already have accepted 'vetoCount' emissions in a row, do nothing
    if (vetoMode == 1 && nAcceptSeq >= vetoCount) return false;

    // Pythia radiator after, emitted and recoiler after.
    int iRadAft = -1, iEmt = -1, iRecAft = -1;
    for (int i = e.size() - 1; i > 0; i--) {
      if      (iRadAft == -1 && e[i].status() == -41) iRadAft = i;
      else if (iEmt    == -1 && e[i].status() ==  43) iEmt    = i;
      else if (iRecAft == -1 && e[i].status() == -42) iRecAft = i;
      if (iRadAft != -1 && iEmt != -1 && iRecAft != -1) break;
    }
    if (iRadAft == -1 || iEmt == -1 || iRecAft == -1) {
      e.list();
      cout << "Error: couldn't find Pythia ISR emission" << endl;
      exit(1);
    }

    // pTemtMode == 0: pT of emitted w.r.t. radiator
    // pTemtMode == 1: min(pT of emitted w.r.t. all incoming/outgoing)
    // pTemtMode == 2: min(pT of all outgoing w.r.t. all incoming/outgoing)
    int xSR      = (pTemtMode == 0) ? 0       : -1;
    int i        = (pTemtMode == 0) ? iRadAft : -1;
    int j        = (pTemtMode != 2) ? iEmt    : -1;
    int k        = -1;
    int r        = (pTemtMode == 0) ? iRecAft : -1;
    double pTemt = pTcalc(e, i, j, k, r, xSR);

#ifdef DBGOUTPUT
    cout << "doVetoISREmission: pTemt = " << pTemt << endl << endl;
#endif

    // Veto if pTemt > pThard
    if (pTemt > pThard) {
      nAcceptSeq = 0;
      nISRveto++;
      return true;
    }

    // Else mark that an emission has been accepted and continue
    nAcceptSeq++;
    accepted = true;
    return false;
  }

//--------------------------------------------------------------------------

  // FSR veto

  bool canVetoFSREmission() { return (vetoMode == 0) ? false : true; }
  bool doVetoFSREmission(int, const Event &e, int iSys, bool) {
    // Must be radiation from the hard system
    if (iSys != 0) return false;

    // If we already have accepted 'vetoCount' emissions in a row, do nothing
    if (vetoMode == 1 && nAcceptSeq >= vetoCount) return false;

    // Pythia radiator (before and after), emitted and recoiler (after)
    int iRecAft = e.size() - 1;
    int iEmt    = e.size() - 2;
    int iRadAft = e.size() - 3;
    int iRadBef = e[iEmt].mother1();
    if ( (e[iRecAft].status() != 52 && e[iRecAft].status() != -53) ||
         e[iEmt].status() != 51 || e[iRadAft].status() != 51) {
      e.list();
      cout << "Error: couldn't find Pythia FSR emission" << endl;
      exit(1);
    }

    // Behaviour based on pTemtMode:
    //  0 - pT of emitted w.r.t. radiator before
    //  1 - min(pT of emitted w.r.t. all incoming/outgoing)
    //  2 - min(pT of all outgoing w.r.t. all incoming/outgoing)
    int xSR = (pTemtMode == 0) ? 1       : -1;
    int i   = (pTemtMode == 0) ? iRadBef : -1;
    int k   = (pTemtMode == 0) ? iRadAft : -1;
    int r   = (pTemtMode == 0) ? iRecAft : -1;

    // When pTemtMode is 0 or 1, iEmt has been selected
    double pTemt = 0.;
    if (pTemtMode == 0 || pTemtMode == 1) {
      // Which parton is emitted, based on emittedMode:
      //  0 - Pythia definition of emitted
      //  1 - Pythia definition of radiated after emission
      //  2 - Random selection of emitted or radiated after emission
      //  3 - Try both emitted and radiated after emission
      int j = iRadAft;
      if (emittedMode == 0 || (emittedMode == 2 && rndmPtr->flat() < 0.5)) j++;

      for (int jLoop = 0; jLoop < 2; jLoop++) {
        if      (jLoop == 0) pTemt = pTcalc(e, i, j, k, r, xSR);
        else if (jLoop == 1) pTemt = min(pTemt, pTcalc(e, i, j, k, r, xSR));
  
        // For emittedMode == 3, have tried iRadAft, now try iEmt
        if (emittedMode != 3) break;
        if (k != -1) swap(j, k); else j = iEmt;
      }

    // If pTemtMode is 2, then try all final-state partons as emitted
    } else if (pTemtMode == 2) {
      pTemt = pTcalc(e, i, -1, k, r, xSR);

    }

#ifdef DBGOUTPUT
    cout << "doVetoFSREmission: pTemt = " << pTemt << endl << endl;
#endif

    // Veto if pTemt > pThard
    if (pTemt > pThard) {
      nAcceptSeq = 0;
      nFSRveto++;
      return true;
    }

    // Else mark that an emission has been accepted and continue
    nAcceptSeq++;
    accepted = true;
    return false;
  }

//--------------------------------------------------------------------------

  // MPI veto

  bool canVetoMPIEmission() { return (MPIvetoMode == 0) ? false : true; }
  bool doVetoMPIEmission(int, const Event &e) {
    if (MPIvetoMode == 1) {
      if (e[e.size() - 1].pT() > pTMPI) {
#ifdef DBGOUTPUT
        cout << "doVetoMPIEmission: pTnow = " << e[e.size() - 1].pT()
             << ", pTMPI = " << pTMPI << endl << endl;
#endif
        return true;
      }
    }
    return false;
  }

//--------------------------------------------------------------------------

  // Functions to return information

  int    getNISRveto() { return nISRveto; }
  int    getNFSRveto() { return nFSRveto; }

private:
  int    nFinal, vetoMode, vetoCount, pThardMode, pTemtMode,
         emittedMode, pTdefMode, MPIvetoMode;
  double pThard, pTMPI;
  bool   accepted;
  // The number of accepted emissions (in a row)
  int nAcceptSeq;
  // Statistics on vetos
  unsigned long int nISRveto, nFSRveto;

};

//==========================================================================

int main(int argc, char* argv[]) {
  if (argc != 3 && argc != 4 && argc != 5 && argc != 6 && argc != 7) {
    cout << "usage: W <options file> <input lhes> <output file> [maxevts] [firstevt] [seed]\n";
    return 0;
  }
  
  
  //random number for smearing
  TRandom3 r;
  // Generator
  //Pythia pythia;
  Pythia pythia("/user2/sfarry/Generators/share/Pythia8/xmldoc", false);

  // Add further settings that can be set in the configuration file
  pythia.settings.addMode("POWHEG:nFinal",    2, true, false, 1, 0);
  pythia.settings.addMode("POWHEG:veto",      0, true, true,  0, 2);
  pythia.settings.addMode("POWHEG:vetoCount", 3, true, false, 0, 0);
  pythia.settings.addMode("POWHEG:pThard",    0, true, true,  0, 2);
  pythia.settings.addMode("POWHEG:pTemt",     0, true, true,  0, 2);
  pythia.settings.addMode("POWHEG:emitted",   0, true, true,  0, 3);
  pythia.settings.addMode("POWHEG:pTdef",     0, true, true,  0, 2);
  pythia.settings.addMode("POWHEG:MPIveto",   0, true, true,  0, 1);
  
  string options = argv[1];
  int maxEvts = -1;
  int firstEvt = 0;
  // Load configuration file
  pythia.readFile(options);
  string output = "";
  if (argc == 3){
    output  = argv[2];
  }
  else{
    string input   = argv[2];
    output  = argv[3];
    maxEvts = argc < 5 ? -1 : static_cast<int>(atof(argv[4]));
    firstEvt = argc < 6 ? 0 : static_cast<int>(atof(argv[5]));
    if (input != "standalone") pythia.readString("Beams:LHEF = "+input);
    if (argc > 6) {
      string seed = argv[6];
      pythia.readString("Random::setSeed = on");
      pythia.readString("Random::seed = "+seed);
    }
  }
    

  // Read in main settings
  int nEvent      = pythia.settings.mode("Main:numberOfEvents");
  int nError      = pythia.settings.mode("Main:timesAllowErrors");
  // Read in POWHEG settings
  int nFinal      = pythia.settings.mode("POWHEG:nFinal");
  int vetoMode    = pythia.settings.mode("POWHEG:veto");
  int vetoCount   = pythia.settings.mode("POWHEG:vetoCount");
  int pThardMode  = pythia.settings.mode("POWHEG:pThard");
  int pTemtMode   = pythia.settings.mode("POWHEG:pTemt");
  int emittedMode = pythia.settings.mode("POWHEG:emitted");
  int pTdefMode   = pythia.settings.mode("POWHEG:pTdef");
  int MPIvetoMode = pythia.settings.mode("POWHEG:MPIveto");
  bool doFxFx      = pythia.settings.flag("JetMatching:doFxFx");
  bool loadHooks  = (vetoMode > 0 || MPIvetoMode > 0);
  bool mcatnlohooks = (doFxFx);


  // Add in user hooks for shower vetoing
  PowhegHooks *powhegHooks = NULL;
  JetMatchingMadgraph *mgHooks = NULL;
  if (mcatnlohooks){
    mgHooks = new JetMatchingMadgraph();
    pythia.setUserHooksPtr((UserHooks *) mgHooks);
  }
  if (loadHooks) {
    // Set ISR and FSR to start at the kinematical limit
    if (vetoMode > 0) {
      pythia.readString("SpaceShower:pTmaxMatch = 0");
      pythia.readString("TimeShower:pTmaxMatch = 1");
    }

    // Set MPI to start at the kinematical limit
    if (MPIvetoMode > 0) {
      pythia.readString("MultipartonInteractions:pTmaxMatch = 2");
    }

    powhegHooks = new PowhegHooks(nFinal, vetoMode, vetoCount,
        pThardMode, pTemtMode, emittedMode, pTdefMode, MPIvetoMode);
    pythia.setUserHooksPtr((UserHooks *) powhegHooks);
  }

  // Initialise and list settings
  pythia.init();

  int ninitrwgt = pythia.info.getInitrwgtSize();

  cout<<ninitrwgt<<" weights in event"<<endl;

  if (firstEvt >0) {
    cout<<"Will Skip "<<firstEvt<<" Events in file"<<endl;
    pythia.LHAeventSkip(firstEvt);
  }
  // Counters for number of ISR/FSR emissions vetoed
  unsigned long int nISRveto = 0, nFSRveto = 0;


  //Variables to be filled
  int W_id = 0, mu_id = 0, tau_id = 0, parton_id;
  double mu_jetdr = -1.0, jet_mudr = -1.0, fwdjet_mudr = -1.0, bwdjet_mudr = -1.0;
  vector<double> parton(8, 0.0);
  vector<double> W(8, 0.0);
  vector<double> mu(8, 0.0);
  vector<double> tau(8, 0.0);
  vector<double> mu_born(8, 0.0);
  vector<double> jet(10, 0.0);
  vector<double> jet2(10, 0.0);
  vector<double> fwdjet(10, 0.0);
  vector<double> bwdjet(10, 0.0);
  vector<double> mujet(8, 0.0);
  vector<double> mufwdjet(8, 0.0);
  vector<double> mubwdjet(8, 0.0);

  int iEvent = 0, iError = 0;
  map<string, double> ws;
  ws["w"] = -1.0;
  int id1 = 0, id2 = 0, id1lhe = 0, id2lhe = 0;
  double x1 = 0.0, x2 = 0.0, x1lhe = 0.0, x2lhe = 0.0;
  double rdm_10pc = 0.0, rdm_15pc = 0.0;

  TFile outputF(output.c_str(), "RECREATE");
  TTree* tree = new TTree("Wjet", "W+j Tree", 1);

  tree->Branch ("evtNum" , &iEvent, "evt/I" );
  tree->Branch( "w"      , &ws["w"] , "w/D"   );
  LHAinitrwgt* initrwgt = pythia.info.initrwgt;
  int i = 0;
  if (initrwgt){
    for (std::map<std::string, Pythia8::LHAweight >::const_iterator ig = pythia.info.initrwgt->weights.begin();
	 ig != pythia.info.initrwgt->weights.end(); ++ig){
      ws["w"+ig->first] = -1.0;
      cout<<"w"+ig->first<<endl;
      tree->Branch( ("w"+ig->first).c_str()   , &ws["w"+ig->first]  , ("w"+ig->first+"/D").c_str());
      ++i;
    }
  }
  tree->Branch("x1"    , &x1    , "x1/D");
  tree->Branch("x2"    , &x2    , "x2/D");
  tree->Branch("id1"   , &id1   , "id1/D");
  tree->Branch("id2"   , &id2   , "id2/D");
  tree->Branch("x1lhe" , &x1lhe , "x1lhe/D");
  tree->Branch("x2lhe" , &x2lhe , "x2lhe/D");
  tree->Branch("id1lhe", &id1lhe, "id1lhe/D");
  tree->Branch("id2lhe", &id2lhe, "id2lhe/D");

  //original parton information
  tree->Branch ("parton_id"  , &parton_id,    "parton_id/I");
  tree->Branch ("parton_px"  , &parton.at(0), "parton_px/D");
  tree->Branch ("parton_py"  , &parton.at(1), "parton_py/D");
  tree->Branch ("parton_pz"  , &parton.at(2), "parton_pz/D");
  tree->Branch ("parton_pt"  , &parton.at(3), "parton_pt/D");
  tree->Branch ("parton_p"   , &parton.at(4), "parton_p/D"  );
  tree->Branch ("parton_phi" , &parton.at(5), "parton_phi/D");
  tree->Branch ("parton_eta"   , &parton.at(6), "parton_y/D"  );

  tree->Branch ("W_id"  , &W_id,    "W_id/I");
  tree->Branch ("W_px"  , &W.at(0), "W_px/D");
  tree->Branch ("W_py"  , &W.at(1), "W_py/D");
  tree->Branch ("W_pz"  , &W.at(2), "W_pz/D");
  tree->Branch ("W_pt"  , &W.at(3), "W_pt/D");
  tree->Branch ("W_p"   , &W.at(4), "W_p/D"  );
  tree->Branch ("W_phi" , &W.at(5), "W_phi/D");
  tree->Branch ("W_y"   , &W.at(6), "W_y/D"  );

  tree->Branch ("mu_id"    , &mu_id   ,  "mu_id/I");
  tree->Branch ("mu_px"    , &mu.at(0),  "mu_px/D");
  tree->Branch ("mu_py"    , &mu.at(1), "mu_py/D");
  tree->Branch ("mu_pz"    , &mu.at(2), "mu_pz/D");
  tree->Branch ("mu_pt"    , &mu.at(3), "mu_pt/D");
  tree->Branch ("mu_p"     , &mu.at(4), "mu_p/D");
  tree->Branch ("mu_phi"   , &mu.at(5), "mu_phi/D");
  tree->Branch ("mu_eta"   , &mu.at(6), "mu_eta/D");
  tree->Branch ("mu_jetdr" , &mu_jetdr, "mu_jetdr/D");

  tree->Branch ("tau_id"    , &tau_id   ,  "tau_id/I");
  tree->Branch ("tau_px"    , &tau.at(0),  "tau_px/D");
  tree->Branch ("tau_py"    , &tau.at(1), "tau_py/D");
  tree->Branch ("tau_pz"    , &tau.at(2), "tau_pz/D");
  tree->Branch ("tau_pt"    , &tau.at(3), "tau_pt/D");
  tree->Branch ("tau_p"     , &tau.at(4), "tau_p/D");
  tree->Branch ("tau_phi"   , &tau.at(5), "tau_phi/D");
  tree->Branch ("tau_eta"   , &tau.at(6), "tau_eta/D");

  
  tree->Branch ("mu_born_px"    , &mu_born.at(0), "mu_born_px/D");
  tree->Branch ("mu_born_py"    , &mu_born.at(1), "mu_born_py/D");
  tree->Branch ("mu_born_pz"    , &mu_born.at(2), "mu_born_pz/D");
  tree->Branch ("mu_born_pt"    , &mu_born.at(3), "mu_born_pt/D");
  tree->Branch ("mu_born_p"     , &mu_born.at(4), "mu_born_p/D");
  tree->Branch ("mu_born_phi"   , &mu_born.at(5), "mu_born_phi/D");
  tree->Branch ("mu_born_eta"   , &mu_born.at(6), "mu_born_eta/D");

  tree->Branch ("jet_px"  , &jet.at(0),  "jet_px/D");
  tree->Branch ("jet_py"  , &jet.at(1),  "jet_py/D");
  tree->Branch ("jet_pz"  , &jet.at(2),  "jet_pz/D");
  tree->Branch ("jet_pt"  , &jet.at(3),  "jet_pt/D");
  tree->Branch ("jet_p"   , &jet.at(4),   "jet_p/D");
  tree->Branch ("jet_phi" , &jet.at(5), "jet_phi/D");
  tree->Branch ("jet_eta" , &jet.at(6), "jet_eta/D");
  tree->Branch ("jet_e"   , &jet.at(7), "jet_e/D");
  tree->Branch ("jet_et"  , &jet.at(8), "jet_et/D");
  tree->Branch ("jet_m"  , &jet.at(9), "jet_m/D");
  tree->Branch ("jet_mudr" , &jet_mudr, "jet_mudr/D");

  tree->Branch ("jet2_px"  , &jet2.at(0),  "jet2_px/D");
  tree->Branch ("jet2_py"  , &jet2.at(1),  "jet2_py/D");
  tree->Branch ("jet2_pz"  , &jet2.at(2),  "jet2_pz/D");
  tree->Branch ("jet2_pt"  , &jet2.at(3),  "jet2_pt/D");
  tree->Branch ("jet2_p"   , &jet2.at(4),  "jet2_p/D");
  tree->Branch ("jet2_phi" , &jet2.at(5),  "jet2_phi/D");
  tree->Branch ("jet2_eta" , &jet2.at(6),  "jet2_eta/D");
  tree->Branch ("jet2_e"   , &jet2.at(7),  "jet2_e/D");
  tree->Branch ("jet2_et"  , &jet2.at(8),  "jet2_et/D");
  tree->Branch ("jet2_m"  ,  &jet2.at(9),  "jet2_m/D");

  tree->Branch ("fwdjet_px"  , &fwdjet.at(0), "fwdjet_px/D");
  tree->Branch ("fwdjet_py"  , &fwdjet.at(1), "fwdjet_py/D");
  tree->Branch ("fwdjet_pz"  , &fwdjet.at(2), "fwdjet_pz/D");
  tree->Branch ("fwdjet_pt"  , &fwdjet.at(3), "fwdjet_pt/D");
  tree->Branch ("fwdjet_p"   , &fwdjet.at(4), "fwdjet_p/D");
  tree->Branch ("fwdjet_phi" , &fwdjet.at(5), "fwdjet_phi/D");
  tree->Branch ("fwdjet_eta" , &fwdjet.at(6), "fwdjet_eta/D");
  tree->Branch ("fwdjet_e"   , &fwdjet.at(7), "fwdjet_e/D");
  tree->Branch ("fwdjet_et"  , &fwdjet.at(8), "fwdjet_et/D");
  tree->Branch ("fwdjet_m"   , &fwdjet.at(9), "fwdjet_m/D");
  tree->Branch ("fwdjet_mudr" , &fwdjet_mudr, "fwdjet_mudr/D");

  tree->Branch ("bwdjet_px"  , &bwdjet.at(0), "bwdjet_px/D");
  tree->Branch ("bwdjet_py"  , &bwdjet.at(1), "bwdjet_py/D");
  tree->Branch ("bwdjet_pz"  , &bwdjet.at(2), "bwdjet_pz/D");
  tree->Branch ("bwdjet_pt"  , &bwdjet.at(3), "bwdjet_pt/D");
  tree->Branch ("bwdjet_p"   , &bwdjet.at(4), "bwdjet_p/D");
  tree->Branch ("bwdjet_phi" , &bwdjet.at(5), "bwdjet_phi/D");
  tree->Branch ("bwdjet_eta" , &bwdjet.at(6), "bwdjet_eta/D");
  tree->Branch ("bwdjet_e"   , &bwdjet.at(7), "bwdjet_e/D");
  tree->Branch ("bwdjet_et"  , &bwdjet.at(8), "bwdjet_et/D");
  tree->Branch ("bwdjet_m"   , &bwdjet.at(9), "bwdjet_m/D");
  tree->Branch ("bwdjet_mudr" , &bwdjet_mudr, "bwdjet_mudr/D");

  tree->Branch ("mujet_px"  , &mujet.at(0) ,  "mujet_px/D");
  tree->Branch ("mujet_py"  , &mujet.at(1) ,  "mujet_py/D");
  tree->Branch ("mujet_pz"  , &mujet.at(2) ,  "mujet_pz/D");
  tree->Branch ("mujet_pt"  , &mujet.at(3) ,  "mujet_pt/D");
  tree->Branch ("mujet_p"   , &mujet.at(4) ,  "mujet_p/D");
  tree->Branch ("mujet_phi" , &mujet.at(5) , "mujet_phi/D");
  tree->Branch ("mujet_eta" , &mujet.at(6) , "mujet_eta/D");
  tree->Branch ("mujet_m"   , &mujet.at(7) , "mujet_m/D");

  tree->Branch ("mufwdjet_px"  , &mufwdjet.at(0) ,  "mufwdjet_px/D");
  tree->Branch ("mufwdjet_py"  , &mufwdjet.at(1) ,  "mufwdjet_py/D");
  tree->Branch ("mufwdjet_pz"  , &mufwdjet.at(2) ,  "mufwdjet_pz/D");
  tree->Branch ("mufwdjet_pt"  , &mufwdjet.at(3) ,  "mufwdjet_pt/D");
  tree->Branch ("mufwdjet_p"   , &mufwdjet.at(4) ,   "mufwdjet_p/D");
  tree->Branch ("mufwdjet_phi" , &mufwdjet.at(5) , "mufwdjet_phi/D");
  tree->Branch ("mufwdjet_eta" , &mufwdjet.at(6) ,   "mufwdjet_eta/D");
  tree->Branch ("mufwdjet_m"   , &mufwdjet.at(7) ,   "mufwdjet_m/D");

  tree->Branch ("mubwdjet_px"  , &mubwdjet.at(0) ,  "mubwdjet_px/D");
  tree->Branch ("mubwdjet_py"  , &mubwdjet.at(1) ,  "mubwdjet_py/D");
  tree->Branch ("mubwdjet_pz"  , &mubwdjet.at(2) ,  "mubwdjet_pz/D");
  tree->Branch ("mubwdjet_pt"  , &mubwdjet.at(3) ,  "mubwdjet_pt/D");
  tree->Branch ("mubwdjet_p"   , &mubwdjet.at(4) ,   "mubwdjet_p/D");
  tree->Branch ("mubwdjet_phi" , &mubwdjet.at(5) , "mubwdjet_phi/D");
  tree->Branch ("mubwdjet_eta" , &mubwdjet.at(6) ,   "mubwdjet_eta/D");
  tree->Branch ("mubwdjet_m"   , &mubwdjet.at(7) ,   "mubwdjet_m/D");

  //store two smearing factors for 10% and 15% uncertainties
  tree->Branch("rdm_10pc", &rdm_10pc, "rdm_10pc/D");
  tree->Branch("rdm_15pc", &rdm_15pc, "rdm_15pc/D");


  // Begin event loop; generate until nEvent events are processed
  // or end of LHEF file
  //int i = 0;

  int totEvts = 0;
  
  while ( maxEvts == -1 || iEvent < maxEvts ) {
    //i++;
    if (iEvent%10000 == 0) cout<<"Event "<<iEvent<<endl;

    //Reset all values
    std::fill(W.begin(), W.end(), 0.0);
    std::fill(mu.begin(), mu.end(), 0.0);
    std::fill(tau.begin(), tau.end(), 0.0);
    std::fill(mu_born.begin(), mu_born.end(), 0.0);
    std::fill(jet.begin(), jet.end(), 0.0);
    std::fill(jet2.begin(), jet2.end(), 0.0);
    std::fill(fwdjet.begin(), fwdjet.end(), 0.0);
    std::fill(bwdjet.begin(), bwdjet.end(), 0.0);
    std::fill(mujet.begin(), mujet.end(), 0.0);
    std::fill(mufwdjet.begin(), mufwdjet.end(), 0.0);
    std::fill(mubwdjet.begin(), mubwdjet.end(), 0.0);

    mu_jetdr = -1;
    jet_mudr = -1;
    fwdjet_mudr = -1;
    bwdjet_mudr = -1;

    // Generate the next event
    //first increment event counter anyway
    ++iEvent;
    if (!pythia.next()) {
      
      // If failure because reached end of file then exit event loop
      if (pythia.info.atEndOfFile()) {
	cout<<"End of file at entry "<<iEvent<<endl;
      break;
      }
      
      // Otherwise count event failure and continue/exit as necessary
      cout << "Warning: event " << iEvent << " failed" << endl;
      if (++iError == nError) {
        cout << "Error: too many event failures.. exiting" << endl;
        break;
      }
      
      continue;
    }
    
    /*
     * Process dependent checks and analysis may be inserted here
     */
    
    // Update ISR/FSR veto counters
    if (loadHooks) {
      nISRveto += powhegHooks->getNISRveto();
      nFSRveto += powhegHooks->getNFSRveto();
    }
    //if (mcatnlohooks) {
    //  nISRveto += mgHooks->getNISRveto();
    //  nFSRveto += mgHooks->getNFSRveto();
    //}
    
    // If nEvent is set, check and exit loop if necessary
    //++iEvent;
    id1 = pythia.info.id1();
    id2 = pythia.info.id2();
    id1lhe = pythia.info.id1pdf();
    id2lhe = pythia.info.id2pdf();
    x1 = pythia.info.x1();
    x2 = pythia.info.x2();
    x1lhe = pythia.info.x1pdf();
    x2lhe = pythia.info.x2pdf();
    ws["w"] = pythia.info.weight();

    map<string, double>* weights = pythia.info.weights_detailed;
    //bool check_weights = true;
    
    if (weights){
      int i = 0;
      for (map<string,double>::iterator iw = weights->begin(); iw !=weights->end(); ++iw){
	//int idx = atoi(iw->first.c_str());
	//if (iEvent == 1 ) cout<<i<<" "<<idx<<" "<<iw->first<<endl;
	ws["w"+iw->first] = iw->second;
	++i;
      }
    }

    if (nEvent != 0 && iEvent == nEvent) break;
    vector<Particle>  Wparts;
    vector<Particle>  mus;
    vector<Particle>  taus;
    vector<Particle>  mus_born;
    vector<fastjet::PseudoJet> particles;
    double R = 0.5;
    fastjet::JetDefinition jet_def(fastjet::antikt_algorithm, R);
    int idxmu = -1;

    for (int i = 0 ; i < pythia.event.size(); ++i ){
      // status -24 , -44, -62
      if ( abs(pythia.event[i].id())  == 24 && pythia.event[i].status() == -62) {
	Wparts.push_back(pythia.event[i]);
      }
      if ( abs(pythia.event[i].id())  == 15 ) {
	taus.push_back(pythia.event[i]);
      }
      if ( abs(pythia.event[i].id())  == 13 &&
	   (abs(pythia.event[pythia.event[i].mother1()].id()) == 24 ||
	    abs(pythia.event[pythia.event[i].mother1()].id()) == 15)){

	int idx = pythia.event[i].iBotCopy();
	while (pythia.event[idx].daughter1() != 0) {
	  idx = abs(pythia.event[pythia.event[idx].daughter1()].id()) == 13 ?
	    pythia.event[idx].daughter1() : pythia.event[idx].daughter2();
	}
	mus_born.push_back(pythia.event[i]);
	mus.push_back(pythia.event[idx]);
	idxmu = idx;
      }
    }

      //if ( abs(pythia.event[i].id())  == 13 &&
      //   isFinalState(pythia.event[i]) && 
      //   fromPart(pythia.event, pythia.event[i], 24) &&
      //   !fromPart(pythia.event, pythia.event[i], 22)) {
      //mus.push_back(pythia.event[i]);
      //mu_mothers.push_back(pythia.event[pythia.event[i].mother1()]);
      //idxmu = i;
      //}

    if (mus.size() == 0){
      for (int i = 0 ; i < pythia.event.size(); ++i ){
	// status -24 , -44, -62
	if ( abs(pythia.event[i].id())  == 13 &&  pythia.event[i].status() == -23){
	  int idx = pythia.event[i].iBotCopy();
	  while (pythia.event[idx].daughter1() != 0) {
	    idx = abs(pythia.event[pythia.event[idx].daughter1()].id()) == 13 ?
		      pythia.event[idx].daughter1() : pythia.event[idx].daughter2();
	  }
	  mus_born.push_back(pythia.event[i]);
	  mus.push_back(pythia.event[idx]);
	  idxmu = idx;
	}
      }
    }


    
    for (int i = 0 ; i < pythia.event.size(); ++i ){
      //Fill Particles fpr jet
      if ( i != idxmu && pythia.event[i].isFinal() && 
	   !(pythia.event[i].isLepton() && pythia.event[i].isNeutral())) //not neutral lepton (neutrino)
	{
	  particles.push_back( fastjet::PseudoJet( pythia.event[i].px(), pythia.event[i].py(),
					  pythia.event[i].pz(), pythia.event[i].e()));
	}
    }
    
    fastjet::ClusterSequence cs(particles, jet_def);
    double ptmin = 10.0;
    vector<fastjet::PseudoJet> jets = sorted_by_pt(cs.inclusive_jets(ptmin));
    vector<fastjet::PseudoJet> fwdjets;
    vector<fastjet::PseudoJet> bwdjets;
    for (int j = 0 ; j < (int)jets.size() ; ++j){
      double dR = 0.0;
      if (mus.size() > 0) dR = get_dR( mus.at(0).p(), jets.at(j));
      if (jets.at(j).eta() > 2.2 && jets.at(j).eta() < 4.2 && dR > 0.5) {
	fwdjets.push_back(jets.at(j));
      }
      else if (jets.at(j).eta() < -2.2 && jets.at(j).eta() > -4.2 && dR > 0.5) {
	bwdjets.push_back(jets.at(j));
      }
    }
    
    if (pythia.event[6].status() == -23){
      getVals(pythia.event[6], parton);
      parton_id = pythia.event[6].id();
    }

    if (Wparts.size()  == 1) {
      getVals(Wparts[0], W, true);
      W_id = Wparts[0].id();
    }

    if (mus.size() > 0) {
      getVals(mus[0], mu);
      mu_id = mus[0].id();
    }
    if (taus.size() > 0) {
      getVals(taus[0], tau);
      tau_id = taus[0].id();
    }
    if (mus_born.size() > 0) {
      getVals(mus_born[0], mu_born);
    }
    if (jets.size() > 0) {
      getVals(jets[0], jet);
      if (mus.size() > 0 ) jet_mudr = get_dR(mus[0].p(), jets[0]);
    }
    if (jets.size() > 1) getVals(jets[1], jet2);
    if (fwdjets.size() > 0) {
      if (mus.size() > 0 ) fwdjet_mudr = get_dR(mus[0].p(), fwdjets[0]);
      getVals(fwdjets[0], fwdjet);
    }
    if (bwdjets.size() > 0) {
      if (mus.size() > 0 ) bwdjet_mudr = get_dR(mus[0].p(), bwdjets[0]);
      getVals(bwdjets[0], bwdjet);
    }

    if (mus.size() == 1 && jets.size() > 0){
      Vec4 mujetmom = Vec4(mus[0].px() + jets[0].px(),
			   mus[0].py() + jets[0].py(),
			   mus[0].pz() + jets[0].pz(),
			   mus[0].e()  + jets[0].e());
      getVals(mujetmom, mujet);
      
    }
    if (mus.size() == 1 && fwdjets.size() > 0){
      Vec4 mufwdjetmom = Vec4(mus[0].px() + fwdjets[0].px(),
			      mus[0].py() + fwdjets[0].py(),
			      mus[0].pz() + fwdjets[0].pz(),
			      mus[0].e()  + fwdjets[0].e());
      getVals(mufwdjetmom, mufwdjet);
      
    }
    if (mus.size() == 1 && bwdjets.size() > 0){
      Vec4 mubwdjetmom = Vec4(mus[0].px() + bwdjets[0].px(),
			      mus[0].py() + bwdjets[0].py(),
			      mus[0].pz() + bwdjets[0].pz(),
			      mus[0].e()  + bwdjets[0].e());
      getVals(mubwdjetmom, mubwdjet);
      
    }
    if (mus.size() == 1){
      for (int j = 0 ; j < (int)jets.size() ; ++j){
	double dR = get_dR(mus.at(0).p(), jets[j]);
	if (mu_jetdr == -1.0 || dR < mu_jetdr) mu_jetdr = dR;
      }
    }

    rdm_10pc = r.Gaus(1.0,0.10);
    rdm_15pc = r.Gaus(1.0,0.15);


    totEvts++;
    if (mus.size() > 0 && ((mus[0].p().eta() > 2 && mus[0].p().eta() < 4.5 && fwdjets.size() > 0) ||  (mus[0].p().eta() < -2 && mus[0].p().eta() > -4.5 && bwdjets.size() > 0)))
      {
	tree->Fill();
      }	
  } // End of event loop.


  TParameter<int> TtotEvts("totEvts", totEvts);
  TtotEvts.Write();
  tree->Write();
  outputF.Close();

  // Statistics, histograms and veto information
  pythia.stat();
  cout << "Number of ISR emissions vetoed: " << nISRveto << endl;
  cout << "Number of FSR emissions vetoed: " << nFSRveto << endl;
  if (powhegHooks){
    cout << "Veto performed with POWHEG Hooks" << endl;
  }
  else if (mcatnlohooks)
    {
      cout<<"Veto performed with mcatnlo fxfx"<<endl;
    }
  cout << endl;
  
  // Done.
  if (powhegHooks) delete powhegHooks;
  //if (mgHooks) delete mgHooks;
  return 0;
}

