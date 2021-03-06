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
using namespace fastjet;


class MyInfo: public PseudoJet::UserInfoBase { 
public:
  int _pdg_id;
  bool _charged_;
  MyInfo(int id, bool charged) : _pdg_id(id), _charged_(charged){};
  int pdg_id() const {return _pdg_id;};
  bool charged() const {return _charged_;};
};

double get_dPhi(Vec4 mom, PseudoJet & jet){
  double p_phi = mom.phi();
  double j_phi = jet.phi_std();
  double dPhi  = abs(p_phi - j_phi) < TMath::Pi() ? abs(p_phi - j_phi) : 2*TMath::Pi() - abs(p_phi - j_phi);
  return dPhi;

}

double get_dR(Vec4 mom, PseudoJet& jet){
  double dPhi  = get_dPhi(mom, jet);
  double dEta  = mom.eta() - jet.eta();
  double dR    = sqrt(dPhi * dPhi + dEta * dEta);
  return dR;

}

vector<Particle> get_hard_partons(Event& e, double pt = 5.0){
  vector<Particle> hard_partons;
  for (int i = 0 ; i < e.size(); ++i){
    if (abs(e[i].id()) < 6 || e[i].id() == 21){
      int status = e[i].status();
      if (status == -23 || status == -24){ // keep all from hard process
	hard_partons.push_back(e[i]);
      }
      else if (status > -80 && status < -30 &&
	       status != -31 && status != -32 &&
	       status != -41 && status != -42 &&
	       e[i].pT() > pt
	       ){ // keep all from subprocesses, isr and fsr above threshold for outgoing particles but not incoming partons
	hard_partons.push_back(e[i]);
      } 
    }
  }
  return hard_partons;
}
vector<Particle> get_highpt_partons(Event& e, double pt = 5){
  vector<Particle> hard_partons;
  for (int i = 0 ; i < e.size(); ++i){
    if (e[i].pT() > pt && (abs(e[i].id()) < 6 || e[i].id() == 21)){
      hard_partons.push_back(e[i]);
    }
  }
  return hard_partons;
}

vector<Particle> get_mesons(Event& e){
  vector<Particle> hard_partons;
  for (int i = 0 ; i < e.size(); ++i){
    int id = abs(e[i].id());
    double pt = e[i].pT();
    if (pt > 1 && (id == 111 || id == 311 || id == 113 || id==213 || id == 221 || id == 331   //light
		   || id == 130 || id ==  310 || id == 311 || id == 311                       //strange
		   || id == 411 || id == 421 || id==10411 || id==10421 || i==433 || id==431   //charm
		   || id == 511 || id == 521 || id == 513 || id == 523 || id==521))           //beauty*/
      {
      hard_partons.push_back(e[i]);
      }
  }
  return hard_partons;
}


/*

//to be calculated...
double get_jet_planar_flow(PseudoJet& jet){
  
  TMatrixD I(2, 2);
  double I00 = 0.0, I10 = 0.0, I11 = 0.0;
  std::vector<PseudoJet> children = jet.constituents();
  std::vector<PseudoJet>::iterator ic;
  double M = jet.M();
  for (ic = children.begin(); ic != children.end(); ++ic){
    Vec4 v((*ic).px(), (*ic).py(), (*ic).pz(), (*ic).e());
    double E = v.e();
    I00 += p
  } 
  double width = num/denom;
  return width;
}
*/

double get_jet_width(PseudoJet& jet){
  std::vector<PseudoJet> children = jet.constituents();
  std::vector<PseudoJet>::iterator ic;
  double num = 0.0;
  double denom = 0.0;
  for (ic = children.begin(); ic != children.end(); ++ic){
    Vec4 v((*ic).px(), (*ic).py(), (*ic).pz(), (*ic).e());
    num += get_dR(v, jet)*v.pT();
    denom += v.pT();
  } 
  double width = num/denom;
  return width;
}

double get_jet_eccentricity(PseudoJet& jet){

  std::vector<PseudoJet> children = jet.constituents();
  std::vector<PseudoJet>::iterator ic;
  //double phi_mean_num = 0.0;
  //double eta_mean_num = 0.0;
  //double denom = 0.0;
  double tan2t_num = 0.0, tan2t_denom = 0.0;

  for (ic = children.begin(); ic != children.end(); ++ic){
    Vec4 mom((*ic).px(), (*ic).py(), (*ic).pz(), (*ic).e());
    double dPhi = jet.phi_std() -  mom.phi();
    double dEta = jet.eta() - mom.eta();
    double E = mom.e();
    //phi_mean_num += dPhi*v.e();
    //eta_mean_num += dEta*v.e();
    //denom += E;
    tan2t_num += 2*E*dPhi*dEta;
    tan2t_denom += E*(dPhi*dPhi - dEta*dEta);

  } 
  //double phi_mean = phi_mean_num/denom;
  //double eta_mean = eta_mean_num/denom;
  double tan2t = tan2t_num/tan2t_denom;
  double theta = atan(tan2t)/2;

  double N = children.size();

  double v1 = 0.0, v2 = 0.0;

  for (ic = children.begin(); ic != children.end(); ++ic){
    Vec4 mom((*ic).px(), (*ic).py(), (*ic).pz(), (*ic).e());
    double dPhi = jet.phi_std() -  mom.phi();
    double dEta = jet.eta() - mom.eta();
    double E = mom.e();
    v1 += (1/N)*E*pow(cos(theta)*dEta - sin(theta)*dPhi,2);
    v2 += (1/N)*E*pow(sin(theta)*dEta + cos(theta)*dPhi,2);
    
  } 

  double maxv = max(v1, v2);
  double minv = min(v1, v2);
  double ecc = 1 - (minv/maxv);
  return ecc;


}



map<string, double> get_strange_vars(PseudoJet& jet){
  std::vector<PseudoJet> children = jet.constituents();
  std::vector<PseudoJet>::iterator ic;
  int nkaons = 0, npions = 0;
  double kaonE = 0, pionE = 0, kaonpt = 0.0, pionpt = 0.0;
  double kaoncE = 0, pioncE = 0, kaoncpt = 0, pioncpt = 0.0;
  double minkaonpt = 0.0, maxkaonpt = 0.0, minpionpt = 0.0, maxpionpt = 0.0;
  double dR_maxkaon = -1.0, dR_maxpion = -1.0;
  double neutralE = 0.0, chargedE = 0.0;
  for (ic = children.begin(); ic != children.end(); ++ic){
    int pdg_id = (*ic).user_info<MyInfo>().pdg_id();
    bool charged = (*ic).user_info<MyInfo>().charged();
    if (charged) chargedE+= (*ic).E();
    else neutralE += (*ic).E();

    if (pdg_id == 130 || pdg_id == 310 || pdg_id == 311 || abs(pdg_id) == 321){
      nkaons++;
      kaonE += (*ic).E();
      kaonpt += (*ic).perp();
      if (abs(pdg_id) == 321){
	kaoncE += (*ic).E();
	kaoncpt += (*ic).perp();
	if ((*ic).perp() > maxkaonpt) {
	  maxkaonpt = (*ic).perp();
	  Vec4 v((*ic).px(), (*ic).py(), (*ic).pz(), (*ic).e());
	  dR_maxkaon = get_dR(v, jet);
	}
	if (((*ic).perp() < minkaonpt)|| minkaonpt == 0.0) minkaonpt = (*ic).perp();
      }
    }
    else if (pdg_id == 111 || abs(pdg_id) == 211){
      npions++;
      pionE += (*ic).E();
      pionpt += (*ic).perp();
      if (abs(pdg_id) == 211){
	pioncE+= (*ic).E();
	pioncpt += (*ic).perp();
	if ((*ic).perp() > maxpionpt ) {
	  maxpionpt = (*ic).perp();
	  Vec4 v((*ic).px(), (*ic).py(), (*ic).pz(), (*ic).e());
	  dR_maxpion = get_dR(v, jet);
	}
	if ((*ic).perp() < minpionpt || minpionpt == 0.0) minpionpt = (*ic).perp();
      }
    }
  }

  double width = get_jet_width(jet);
  double eccentricity = get_jet_eccentricity(jet);

  map<string, double> a;
  a["nkaons"]      = nkaons;
  a["kaonE"]       = kaonE;
  a["kaoncE"]      = kaoncE;
  a["npions"]      = npions;
  a["pionE"]       = pionE;
  a["pioncE"]      = pioncE;
  a["maxkaonpt"]   = maxkaonpt;
  a["minkaonpt"]   = minkaonpt;
  a["maxpionpt"]   = maxpionpt;
  a["minpionpt"]   = minpionpt;
  a["kaonpt"]      = kaonpt;
  a["kaoncpt"]     = kaoncpt;
  a["pionpt"]      = pionpt;
  a["pioncpt"]     = pioncpt;
  a["dR_maxkaon"]  = dR_maxkaon;
  a["dR_maxpion"]  = dR_maxpion;
  a["neutralE"]   = neutralE;
  a["chargedE"]   = chargedE;
  a["width"]      = width;
  a["eccentricity"] = eccentricity;
  return a;
}

map<string, double> get_flavour(PseudoJet& jet, vector<Particle>& partons, Event& event){
  int id = -999;
  double dr = -1, pt = -1.0, type = 0;
  //first of all, remove any partons from the same decay chain which can tag the jet
  //keep only mother
  std::vector<int> indices;
  for (int i = 0 ; i < (int)partons.size(); ++i){ 
    double dr2 = get_dR(partons.at(i).p(), jet);
    if (dr2 < 0.5) indices.push_back(partons.at(i).index());
  }

  for (int i = 0 ; i < (int)partons.size(); ++i){
    double dr_tmp = get_dR(partons.at(i).p(), jet);
    double pt_tmp = partons.at(i).pT();

    /*if ( dr != -1 && dr < 0.3 && dr_tmp < 0.3){// if both partons are within 0.3 of the jet, keep the highest pt one
	if (pt_tmp > pt){
	  dr = dr_tmp;
	  id = partons.at(i).id();
	  pt = pt_tmp;
	  type = floor(abs(partons.at(i).status())/10.0); // 2 - hard scatter, 3 - subprocess, 4 - ISR, 5 - FSR
	}
	}
    
    if (dr_tmp < 0.5){
      int mother_idx = partons.at(i).mother1();
      if (std::find(indices.begin(), indices.end(), mother_idx) == indices.end()){
	Particle& mother = event.at(mother_idx);
	if (partons.at(i).id() != mother.id()){
	  cout<<dr_tmp<<" "<<pt_tmp<<" "<<partons.at(i).id()<<" "<<partons.at(i).status()<<endl;
	  cout<<"mother: "<<get_dR(mother.p(), jet)<<" "<<mother.pT()<<" "<<mother.id()<<" "<<mother.status()<<endl;
	}
	}*/
    if ( (dr == -1 && dr_tmp < 0.5) || dr_tmp < dr) // otherwise just pick closest
      {
	//don't use if mother is also in the jet
	int mother_idx = partons.at(i).mother1();
	if (std::find(indices.begin(), indices.end(), mother_idx) == indices.end()){
	  dr = dr_tmp;
	  id = partons.at(i).id();
	  pt = pt_tmp;
	  type = floor(abs(partons.at(i).status())/10.0);
	}
	else{
	  cout<<"mother is here"<<endl;
	}
      }
  }
  std::map<string, double> flav;
  flav["id"] = abs(id);
  flav["pt"] = pt;
  flav["type"] = type;
  return flav;
}

int get_flavour_by_meson(PseudoJet& jet, vector<Particle>& mesons){
  int flav = -999;
  double pt = -1;
  for (int i = 0 ; i < (int)mesons.size(); ++i){
    double dr = get_dR(mesons.at(i).p(), jet);
    double pt_tmp = mesons.at(i).pT();
    if ( (dr < 0.3) && (pt == -1 || pt_tmp > pt)){
      pt = pt_tmp;
      flav = mesons.at(i).id();
    }
  }
  return flav;
}

void getVals(Vec4 mom, std::map<string, double>& vals){
  //vector<double> vals(7, 0.0);
  vals["e" ] = mom.e();
  vals["px"] = mom.px();
  vals["py"] = mom.py();
  vals["pz"] = mom.pz();
  vals["pt"] = mom.pT();
  vals["p"] = mom.pAbs();
  vals["phi"] = mom.phi();
  vals["y"] = mom.rap();
  vals["eta"] = mom.eta();
  vals["m"] = mom.mCalc();
  //return vals;
}
void getVals(PseudoJet& jet, map<string, double>& vals, vector<Particle> hard_partons, vector<Particle> mesons, Event& event){
  //vector<double> vals(9, 0.0);
  vals["px"]   = jet.px();
  vals["py"]   = jet.py();
  vals["pz"]   = jet.pz();
  vals["pt"]   = sqrt(jet.px() * jet.px() + jet.py() * jet.py());
  vals["p"]    = sqrt(jet.pt() * jet.pt() + jet.pz() * jet.pz());
  vals["phi"]  = jet.phi_std();
  vals["eta"]  = jet.eta();
  vals["e"]    = jet.e();
  vals["et"]   = jet.Et();
  vals["m"]    = jet.m();
  vals["mult"] = jet.constituents().size();

  map<string, double> strange_vars = get_strange_vars(jet);
  map<string, double>::iterator im;
  for (im = strange_vars.begin(); im != strange_vars.end(); ++im) vals[(*im).first] = (*im).second;
  std::map<string, double> flav = get_flavour(jet, hard_partons, event);
  vals["flav"] = flav["id"];
  vals["flav_partonpt"] = flav["pt"];
  vals["flav_type"] = flav["type"];
  vals["flav_meson"] = get_flavour_by_meson(jet, mesons);

  //return vals;
}
/*
void getFlavVals(PseudoJet& jet, vector<Particle> hard_partons, map< string, double>& vals){
  //vector<double> vals(9, 0.0);
  map<string, double> strange_vars = get_strange_vars(jet);
  map<string, double>::iterator im;
  for (im = strange_vars.begin(); im != strange_vars.end(); ++im) vals[(*im).first] = (*im).second;
  vals["flav"] = get_flavour(jet, hard_partons);
  }*/
void getVals(Particle& part, std::map<string, double>& vals){
  getVals(part.p(), vals);
  vals["id"] = part.id();
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
  if (argc !=3 && argc != 4 && argc != 5 && argc != 6) {
    cout << "usage: muej <options file> <input lhes> <output file> [maxevts] [firstevt] (input lhes)\n";
    cout << "usage: muej <options file> <output file> [maxevts] [seed] (just run pythia)\n";
    return 0;
  }

  //random number for smearing
  TRandom3 r;

  // Generator
  //Pythia pythia("/user2/sfarry/Generators/pythia8205/xmldoc", false);x
  Pythia pythia("/user2/sfarry/Generators/share/Pythia8/xmldoc", false);

  string options = argv[1];
  int maxEvts = -1;
  int firstEvt = 0;
  // Load configuration file
  pythia.settings.addMode("POWHEG:nFinal",    2, true, false, 1, 0);
  pythia.settings.addMode("POWHEG:veto",      0, true, true,  0, 2);
  pythia.settings.addMode("POWHEG:vetoCount", 3, true, false, 0, 0);
  pythia.settings.addMode("POWHEG:pThard",    0, true, true,  0, 2);
  pythia.settings.addMode("POWHEG:pTemt",     0, true, true,  0, 2);
  pythia.settings.addMode("POWHEG:emitted",   0, true, true,  0, 3);
  pythia.settings.addMode("POWHEG:pTdef",     0, true, true,  0, 2);
  pythia.settings.addMode("POWHEG:MPIveto",   0, true, true,  0, 1);
  pythia.readFile(options);

  bool readLHE = false;
  if ( argc >=3 && strstr(argv[2], ".lhe") != NULL ) readLHE = true;
  


  string output = "";
  if (!readLHE){
    if (argc >= 3){
      output  = argv[2];
      maxEvts = argc < 4 ? pythia.settings.mode("Main:numberOfEvents") : static_cast<int>(atof(argv[3]));
      if (argc >= 5){
	//seed = static_cast<int>(atof(argv[4]));
	string seed = argv[4];
	pythia.readString("Random:setSeed = 1");
	pythia.readString("Random:seed = "+seed);
      }
    }
  }
  else{
    string input   = argv[2];
    output  = argv[3];
    maxEvts = argc < 5 ? -1 : static_cast<int>(atof(argv[4]));
    firstEvt = argc < 6 ? 0 : static_cast<int>(atof(argv[5]));
    // Add further settings that can be set in the configuration file
    //pythia.settings.addFlag("JetMatching:doFxFx", false);
    pythia.readString("Beams:LHEF = "+input);

  }


  // Read in main settings
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
  bool doFxFx     = pythia.settings.flag("JetMatching:doFxFx");
  bool loadHooks  = (vetoMode > 0 || MPIvetoMode > 0);
  bool mcatnlohooks = (doFxFx);

  cout<<"Veto Mode: "<<vetoMode<<endl;
  cout<<"MPIvetoMode: "<<MPIvetoMode<<endl;
  cout<<"ptHarde: "<<pThardMode<<endl;

  // Add in user hooks for shower vetoing
  PowhegHooks *powhegHooks = NULL;
  JetMatchingMadgraph* mgHooks = NULL;
  if (mcatnlohooks){
    mgHooks = new JetMatchingMadgraph();
    pythia.setUserHooksPtr(mgHooks);
  }
  else if (loadHooks) {
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


  if (firstEvt >0) {
    cout<<"Will Skip "<<firstEvt<<" Events in file"<<endl;
    pythia.LHAeventSkip(firstEvt);
  }
  // Counters for number of ISR/FSR emissions vetoed
  unsigned long int nISRveto = 0, nFSRveto = 0;


  //Variables to be filled
  //int Z_id = 0, mup_id = 0, mum_id = 0, parton_id = 0;
  double mu_jetdr = -1.0, e_jetdr = -1.0, jet_dr = -1.0, fwdjet_dr = -1.0, bwdjet_dr = -1.0;

  std::map<string, std::map<string, double> > outParts;
  outParts["parton"]  = std::map<string, double>();
  outParts["t"]       = std::map<string, double>();
  outParts["tbar"]    = std::map<string, double>();
  outParts["mu"]      = std::map<string, double>();
  outParts["e"]       = std::map<string, double>();
  outParts["mu_born"] = std::map<string, double>();
  outParts["e_born"]  = std::map<string, double>();
  outParts["diell"]   = std::map<string, double>();
  outParts["muej"]    = std::map<string, double>();

  std::map<string, std::map<string, double> > outJets;
  outJets["jet"]      = std::map<string, double>();
  outJets["jet2"]     = std::map<string, double>();
  outJets["fwdjet"]   = std::map<string, double>();
  outJets["bwdjet"]   = std::map<string, double>();
  outJets["mufwdjet"] = std::map<string, double>();
  outJets["mubwdjet"] = std::map<string, double>();
  


  /*
  std::map<string, double> parton;
  std::map<string, double> Z;
  std::map<string, double> mup;
  std::map<string, double> mum;
  std::map<string, double> mup_born;
  std::map<string, double> mum_born;
  std::map<string, double> dimu;
  std::map<string, double> jet;
  std::map<string, double> jet_flav;
  std::map<string, double> jet2;
  std::map<string, double> fwdjet;
  std::map<string, double> bwdjet;
  std::map<string, double> mujet;
  std::map<string, double> mufwdjet;
  std::map<string, double> mubwdjet;
  */
  std::map<string, double> jet_flav;
  std::vector<string> part_vars     = {"px", "py", "pz", "e", "pt", "phi", "eta", "y", "m", "id"};
  std::vector<string> jet_vars      = {"px", "py", "pz", "e", "pt", "phi", "eta", "y", "m", "mult"};
  std::vector<string> jetflav_vars  = {"nkaons", "npions", "kaonE", "pionE",
				       "maxkaonpt", "minkaonpt", "maxpionpt", "minpionpt",
				       "kaonpt", "pionpt", "flav", "flav_meson",
				       "flav_partonpt", "flav_hardscatter", "flav_type",
				       "dR_maxkaon", "kaoncpt", "kaoncE",
				       "pioncE", "pioncpt", "dR_maxpion", "neutralE", "chargedE",
                                       "width", "eccentricity"};

  std::map<string, map<string, double> >::iterator im;
  for (im = outParts.begin() ; im != outParts.end(); ++im){
    for (int i = 0 ; i < (int)part_vars.size() ; ++i) {
      (*im).second[part_vars.at(i)] = 0.0;
    }
  }
  for (im = outJets.begin() ; im != outJets.end(); ++im){
    for (int i = 0 ; i < (int)jet_vars.size() ; ++i) {
      (*im).second[jet_vars.at(i)] = 0.0;
    }
    for (int i = 0 ; i < (int)jetflav_vars.size() ; ++i) {
      (*im).second[jetflav_vars.at(i)] = 0.0;
    }
  }

  int iEvent = 0, iError = 0;
  map<string, double> ws;
  ws["w"] = -1.0;
  int id1 = 0, id2 = 0, id1lhe = 0, id2lhe = 0;
  double x1 = 0.0, x2 = 0.0, x1lhe = 0.0, x2lhe = 0.0;


  TFile outputF(output.c_str(), "RECREATE");
  TTree* tree = new TTree("ttbar", "Zj Tree", 1);

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
  tree->Branch("id1"   , &id1   , "id1/I");
  tree->Branch("id2"   , &id2   , "id2/I");
  tree->Branch("x1lhe" , &x1lhe , "x1lhe/D");
  tree->Branch("x2lhe" , &x2lhe , "x2lhe/D");
  tree->Branch("id1lhe", &id1lhe, "id1lhe/I");
  tree->Branch("id2lhe", &id2lhe, "id2lhe/I");

  //set tuple for particle information

  //std::map<string, map<string, double> >::iterator im;
  std::map<string, double>::iterator ip;
  for (im = outParts.begin() ; im != outParts.end(); ++im){
    std::map<string, double>& part = (*im).second;
    for (ip = part.begin() ; ip != part.end(); ++ip){
      tree->Branch(((*im).first+"_"+(*ip).first).c_str(), &(*ip).second, ((*im).first+"_"+(*ip).first+"/D").c_str());
    }
  }
  //original parton information

  for (im = outJets.begin() ; im != outJets.end(); ++im){
    std::map<string, double>& jet = (*im).second;
    for (ip = jet.begin() ; ip != jet.end(); ++ip){
      tree->Branch(((*im).first+"_"+(*ip).first).c_str(), &(*ip).second, ((*im).first+"_"+(*ip).first+"/D").c_str());
    }
  }

  // Begin event loop; generate until nEvent events are processed
  // or end of LHEF file
  //int i = 0;

  int totEvts = 0;
  
  while ( maxEvts == -1 || iEvent < maxEvts ) {
    //i++;
    if (iEvent%10000 == 0) cout<<"Event "<<iEvent<<endl;

    //Reset all values
    

    for (im = outParts.begin() ; im != outParts.end(); ++im){
      std::map<string, double>& part = (*im).second;
      for (ip = part.begin() ; ip != part.end(); ++ip){
	(*ip).second = 0.0;
      }
    }
    //original parton information
    
    for (im = outJets.begin() ; im != outJets.end(); ++im){
      std::map<string, double>& jet = (*im).second;
      for (ip = jet.begin() ; ip != jet.end(); ++ip){
	(*ip).second = 0.0;
      }
    }
    
    mu_jetdr = -1.0;
    e_jetdr  = -1.0;
    jet_dr  = -1.0;
    fwdjet_dr = -1.0;
    bwdjet_dr = -1.0;

    // Generate the next event
    //first increment event counter anyway
    ++iEvent;
    if (!pythia.next()) {
      
      // If failure because reached end of file then exit event loop
      if (pythia.info.atEndOfFile()) break;
      
      // Otherwise count event failure and continue/exit as necessary
      cout << "Warning: event " << iEvent << " failed" << endl;
      if (++iError == nError) {
        cout << "Error: too many event failures.. exiting" << endl;
        break;
      }
      
      continue;
    }
    
    std::vector<Particle> hard_partons = get_hard_partons(pythia.event);
    //std::vector<Particle> highpt_partons = get_highpt_partons(pythia.event);
    std::vector<Particle> mesons       = get_mesons(pythia.event);
    /*
     * Process dependent checks and analysis may be inserted here
     */
    // Update ISR/FSR veto counters
    if (loadHooks) {
      nISRveto += powhegHooks->getNISRveto();
      nFSRveto += powhegHooks->getNFSRveto();
    }
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
    if (weights){
      int i = 0;
      for (map<string,double>::iterator iw = weights->begin(); iw !=weights->end(); ++iw){

	ws["w"+iw->first] = iw->second;
	++i;
      }
    }
    
    vector<Particle>  tops;
    vector<Particle>  antitops;
    vector<Particle>  mus;
    vector<Particle>  es;
    vector<Particle>  mus_born;
    vector<Particle>  es_born;
    vector<PseudoJet> particles;
    double R = 0.5;
    JetDefinition jet_def(antikt_algorithm, R);
    int idxmu = -1, idxe = -1;
    for (int i = 0 ; i < pythia.event.size(); ++i ){
      // status -24 , -44, -62
      if ( pythia.event[i].id()  == 6 && pythia.event[i].status() == -22) {
	tops.push_back(pythia.event[i]);
      }
      if ( pythia.event[i].id()  == -6 && pythia.event[i].status() == -22) {
	antitops.push_back(pythia.event[i]);
      }
      if ( (abs(pythia.event[i].id())  == 13 || abs(pythia.event[i].id()) == 11)
	   && (abs(pythia.event[pythia.event[i].mother1()].id()) == 24
	       || abs(pythia.event[pythia.event[i].mother1()].id()) == 23
	       || abs(pythia.event[pythia.event[i].mother1()].id()) == 15))
	{
	  int idx = pythia.event[i].iBotCopy();
	  while (pythia.event[idx].daughter1() != 0) {
	    if ( abs(pythia.event[pythia.event[idx].daughter1()].id()) == 13 ||
		 abs(pythia.event[pythia.event[idx].daughter1()].id()) == 11 ){
	      idx = pythia.event[idx].daughter1();
	    }
	    else{
	      idx = pythia.event[idx].daughter2();
	    }
	  }
	  if (abs(pythia.event[i].id()) == 13) {
	    mus_born.push_back(pythia.event[i]);
	    mus.push_back(pythia.event[idx]);
	    idxmu = idx;
	  }
	  else {
	    es_born.push_back(pythia.event[i]);
	    es.push_back(pythia.event[idx]);
	    idxe = idx;
	  }
	}
    }

    if (mus.size() == 0 && es.size() == 0){
      for (int i = 0 ; i < pythia.event.size(); ++i ){
	if ( (abs(pythia.event[i].id())  == 13 || abs(pythia.event[i].id() == 11)) &&  pythia.event[i].status() == -23){
	  // status -24 , -44, -62
	  if (abs(pythia.event[i].id()) == 13){
	    int idx = pythia.event[i].iBotCopy();
	    while (pythia.event[idx].daughter1() != 0) {
	      idx = abs(pythia.event[pythia.event[idx].daughter1()].id()) == 13 ?
		pythia.event[idx].daughter1() : pythia.event[idx].daughter2();
	    }
	    mus_born.push_back(pythia.event[i]);
	    mus.push_back(pythia.event[idx]);
	    idxmu = idx;
	  }
	  else if (abs(pythia.event[i].id()) == 11){
	    int idx = pythia.event[i].iBotCopy();
	    while (pythia.event[idx].daughter1() != 0) {
	      idx = abs(pythia.event[pythia.event[idx].daughter1()].id()) == 13 ?
		pythia.event[idx].daughter1() : pythia.event[idx].daughter2();
	    }
	    es_born.push_back(pythia.event[i]);
	    es.push_back(pythia.event[idx]);
	    idxe = idx;
	  }
	}
      }
    }
    
    for (int i = 0 ; i < pythia.event.size(); ++i ){
      //Fill Particles fpr jet
      if ( i != idxmu && i != idxe && pythia.event[i].isFinal() && 
	   !(pythia.event[i].isLepton() && pythia.event[i].isNeutral())) //not neutral lepton (neutrino)
	{
	  PseudoJet p(pythia.event[i].px(), pythia.event[i].py(),
		      pythia.event[i].pz(), pythia.event[i].e());
	  p.set_user_info(new MyInfo(pythia.event[i].id(), pythia.event[i].isCharged()));
	  particles.push_back( p) ;
	}
    }
    ClusterSequence cs(particles, jet_def);
    double ptmin = 10.0;
    vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets(ptmin));
    vector<PseudoJet> fwdjets;
    vector<PseudoJet> bwdjets;
    for (int j = 0 ; j < (int)jets.size() ; ++j){
      double dR = -1.0;
      if (mus.size() > 0 && es.size() > 0){
	dR = min(get_dR( mus.at(0).p(), jets.at(j)), get_dR( es.at(0).p(), jets.at(j)));
      }
      else if (mus.size() > 0) dR = get_dR( mus.at(0).p(), jets.at(j));
      else if (es.size() > 0) dR = get_dR( es.at(0).p(), jets.at(j));

      if (jets.at(j).eta() >2.2 && jets.at(j).eta() < 4.2 && dR > 0.5) {
	fwdjets.push_back(jets.at(j));
      }
      else if (jets.at(j).eta() < -2.2 && jets.at(j).eta() > -4.2 && dR > 0.5) {
	bwdjets.push_back(jets.at(j));
      }
    }
    
    if (pythia.event[6].status() == -23){
      getVals(pythia.event[6], outParts["parton"]);
    }

    if (tops.size()  == 1) {
      getVals(tops[0], outParts["t"]);
      //Z_id = Zparts[0].id();
    }
    if (antitops.size() > 0 ) {
      getVals(antitops[0], outParts["tbar"]);
      //mup_id = mups[0].id();
    }

    idxmu = -1.0;
    idxe  = -1.0;

    if (mus.size() > 0) idxmu = 0;
    if (es.size() > 0) idxe = 0;

    if (mus.size() > 1 && es.size() == 1 &&
	(mus.at(0).charge() == es.at(0).charge()) &&
	(mus.at(1).charge() != es.at(0).charge()))
      {
	idxmu = 1;
      }
    if (es.size() > 1 && mus.size() == 1 &&
	(es.at(0).charge() == mus.at(0).charge()) &&
	(es.at(1).charge() != mus.at(0).charge()))
      {
	idxe = 1;
      }
    
    
    if (idxmu != -1.0) {
      getVals(mus[idxmu], outParts["mu"]);
      getVals(mus_born[idxmu], outParts["mu_born"]);
    }
    if (idxe != -1.0) {
      getVals(es_born[0], outParts["e_born"]);
      getVals(es[0], outParts["e"]);
    }

    if (idxmu != -1.0 && idxe != -1.0){
      Vec4 diell_p = mus[idxmu].p() + es[idxe].p();
      getVals(diell_p, outParts["diell"]);
    }
    if (idxmu != -1.0 && idxe != -1.0 && jets.size() > 0){
      Vec4 j(jets[0].px(), jets[0].py(), jets[0].pz(), jets[0].e());
      Vec4 muej_p = mus[idxmu].p() + es[idxe].p() + j;
      getVals(muej_p, outParts["muej"]);
    }
    if (jets.size() > 0) {
      getVals(jets[0], outJets["jet"], hard_partons, mesons, pythia.event);
      if (idxmu != -1.0) jet_dr = get_dR( mus.at(idxmu).p(), jets[0]);
      if (idxe != -1.0)  jet_dr  = min(jet_dr, get_dR( es.at(idxe).p(), jets[0]));
    }
    if (jets.size() > 1) getVals(jets[1], outJets["jet2"], hard_partons, mesons, pythia.event);
    if (fwdjets.size() > 0) {
      getVals(fwdjets[0], outJets["fwdjet"], hard_partons, mesons, pythia.event);
      if (idxmu != -1.0) fwdjet_dr = get_dR( mus.at(idxmu).p(), fwdjets[0]);
      if (idxe  != -1.0) fwdjet_dr = min(fwdjet_dr, get_dR( es.at(idxe).p(), fwdjets[0]));
    }
    if (bwdjets.size() > 0) {
      getVals(bwdjets[0], outJets["bwdjet"], hard_partons, mesons, pythia.event);
      if (idxmu != -1.0) bwdjet_dr = get_dR( mus.at(idxmu).p(), bwdjets[0]);
      if (idxe  != -1.0) bwdjet_dr = min(bwdjet_dr, get_dR( es.at(idxe).p(), bwdjets[0]));
    }

    if (idxmu != -1.0){
      for (int j = 0 ; j < (int)jets.size() ; ++j){
	double dR = get_dR(mus.at(idxmu).p(), jets[j]);
	if (mu_jetdr == -1.0 || dR < mu_jetdr) mu_jetdr = dR;
      }
    }
    if (idxe != -1.0){
      for (int j = 0 ; j < (int)jets.size() ; ++j){
	double dR = get_dR(es.at(idxe).p(), jets[j]);
	if (e_jetdr == -1.0 || dR < e_jetdr) e_jetdr = dR;
      }
    }

    totEvts++;
    bool reduce_size = false;

    if (reduce_size){
    if (idxmu != -1 && idxe != -1 &&
	((mus[idxmu].p().eta() > 2 && mus[idxmu].p().eta() < 4.5 && es[idxe].p().eta() > 2 && es[idxe].p().eta() < 4.5 && fwdjets.size() > 0)
	 || (mus[idxmu].p().eta() < -2 && mus[idxmu].p().eta() > -4.5 && es[idxe].p().eta() < -2 && es[idxe].p().eta() > -4.5 && bwdjets.size() > 0))) tree->Fill();
    }
    else{
      if (idxmu != -1 || idxe != -1){
	tree->Fill();
      }
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
  //if (mgHooks)     delete mgHooks;
  return 0;
}

