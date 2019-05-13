#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

template <class T>
void printVector (vector<T> &v) {
  for (unsigned i=0; i<v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int maxEnlaces(vector<string> &strings, vector<bool> &choosen, int i,
    unordered_set<string> &yaEmparejados) {

  if (i+1 == strings.size()) {
    return 0;
  } else if ( choosen[i] ) {
    return maxEnlaces(strings, choosen, i+1, yaEmparejados);
  }

  int max_enlaces = 0;
  string sb1, sb2, big_str = strings[i];

  for (int j=i+1; j<strings.size(); j++) {
    for (int k=1; k<=min(big_str.length(), strings[j].length()); k++) {
      sb1 = big_str.substr( big_str.length()-k);
      sb2 = strings[j].substr( strings[j].length()-k);
      if ( yaEmparejados.find(sb1) == yaEmparejados.end() && sb1 == sb2) {
        choosen[i] = true;
        choosen[j] = true;
        yaEmparejados.insert(sb1);
        max_enlaces = max (max_enlaces, 2+maxEnlaces(strings, choosen, i+1, yaEmparejados));
        choosen[i] = false;
        choosen[j] = false;
        yaEmparejados.erase(sb1);
      }
    }
  }
  return max_enlaces;
}

int Hack(vector<string> &strings) {
  vector <bool> choosen (strings.size(), false);
  unordered_set<string> yaEmparejados;
  return maxEnlaces(strings, choosen, 0, yaEmparejados);
}

int main() {
  int T, N;
  string str;
  vector<string> v;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N;
    v.clear();
    v.resize(N);
    for (int j=0; j<N; j++) {
      cin >> str;
      v[j] = str;
    }
    cout << "Case #" << i+1 << ": " << Hack(v) <<endl;
  }
}
