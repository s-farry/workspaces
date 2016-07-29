#ifndef DIF_H
#define DIF_H

// System headers.
#include <iomanip>
#include <iostream>

// ROOT headers.
#include "TLorentzVector.h"
#include "TRandom3.h"
#include "TGraphErrors.h"

using namespace std;

// The decay-in-flight class.
class DiF {
  
public:
  
  // Constructor.
  //
  // The values for the pion to kaon ratio are taken from Table 5 of
  // the W -> mu analysis note, LHCb-ANA-2014-049.
  DiF(double inZ = 12.5, int seed = 65539) 
    : rndm(seed), ratio(5), mPi(139.6), mK(493.7), tPi(55.8), tK(7.2), z(inZ) {
    ratio.SetPoint(0, 2.25, 1.92); ratio.SetPointError(0, 0.25, 0.03);
    ratio.SetPoint(1, 2.75, 2.23); ratio.SetPointError(1, 0.25, 0.04);
    ratio.SetPoint(2, 3.25, 2.44); ratio.SetPointError(2, 0.25, 0.05);
    ratio.SetPoint(3, 3.75, 2.48); ratio.SetPointError(3, 0.25, 0.06);
    ratio.SetPoint(4, 4.25, 2.76); ratio.SetPointError(4, 0.25, 0.09);
  };

  // Perform a two-body decay.
  // 
  // The decay defaults to a muon and neutrino (in GeV) and calculates the
  // mass of the mother from the four-vector. If inM0 != -1 then the mass of
  // the mother is set to this value. This method is included for numerical
  // precision. The energy units do not matter, bust must be consistent.
  vector<TLorentzVector> decay(TLorentzVector &mom, double inM0 = -1,
			       double inM1 = 105.7, double inM2 = 0) {
    // Masses.
    double m0 = inM0 == -1 ? mom.M() : inM0;
    double m1 = inM1;
    double m2 = inM2;
    
    // Energies and absolute momentum in the rest frame.
    double e1   = 0.5 * (m0*m0 + m1*m1 - m2*m2) / m0;
    double e2   = 0.5 * (m0*m0 + m2*m2 - m1*m1) / m0;
    double pAbs = 0.5 * sqrt( (m0 - m1 - m2) * (m0 + m1 + m2)
			      * (m0 + m1 - m2) * (m0 - m1 + m2) ) / m0;
    
    // Isotropic angles give three-momentum.
    double cosTheta = 2.0 * rndm.Uniform() - 1.0;
    double sinTheta = sqrt(1.0 - cosTheta * cosTheta);
    double phi      = 2.0 * M_PI * rndm.Uniform();
    double pX       = pAbs * sinTheta * cos(phi);
    double pY       = pAbs * sinTheta * sin(phi);
    double pZ       = pAbs * cosTheta;
    
    // Fill four-momenta and boost them away from mother rest frame.
    vector<TLorentzVector> children;
    children.push_back(TLorentzVector(pX, pY, pZ, e1));
    children.push_back(TLorentzVector(-pX, -pY, -pZ, e2));
    for (int iChild = 0; iChild < (int)children.size(); ++iChild)
      children[iChild].Boost(mom.BoostVector());
    return children;
  };

  // Calculate the pair (weight, pT) for a track. Units must be given in MeV.
  pair<double, double> weight(TLorentzVector track) {
    pair<double, double> result;
    double r = ratio.Eval(track.Eta());
    vector<TLorentzVector> children;
    double m(mPi), t(tPi);
    if (rndm.Uniform() > 1.0 / (1.0 + r)) {m = mK; t = tK;}
    children = decay(track, m);
    result.first  = 1.0 - exp(-z / (t*children[0].P()));
    result.second = children[0].Pt();
    return result;
  }

  // Print a TLorentzVector (for convenience).
  void print(TLorentzVector vec, ostream &stream = cout) {
    stream << setprecision(2) << scientific << "("
	   << setw(9) << vec.X() << ", "
	   << setw(9) << vec.Y() << ", "
	   << setw(9) << vec.Z() << ", "
	   << setw(9) << vec.T() << ")";
  };

private:

  TRandom3     rndm;    // Random number generator.
  TGraphErrors ratio;   // Pion to kaon ratio for pT > 20 and variable eta.
  double       mPi, mK; // Kaon and pion masses.
  double       tPi, tK; // Kaon and pion lifetimes.
  double       z;       // Flight distance of track.
};

#endif // DIF_H
