// Local.
#include "dif.h"

// The main test program.
int main() {

  // Create a pion.
  TLorentzVector pion(-230, 3400, 34002.0, 0);
  pion.SetE(sqrt(pion.P() * pion.P() + 139.6 * 139.6));

  // Decay it.
  DiF dif;
  vector<TLorentzVector> children = dif.decay(pion);
  cout <<   "pion:     "; dif.print(pion);
  cout << "\nmuon:     "; dif.print(children[0]);
  cout << "\nneutrino: "; dif.print(children[1]);
  cout << "\ncheck:    "; dif.print(children[0] + children[1] - pion);
  cout << "\n";

  // Calculate the weight (new decay).
  pair<double, double> weight = dif.weight(pion);
  cout << "weight:  " << weight.first << "\n";
  cout << "pion pT: " << pion.Pt() << "\n";
  cout << "muon pT: " << weight.second << "\n";

  return 0;
}
