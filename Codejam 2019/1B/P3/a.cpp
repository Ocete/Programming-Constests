#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool just(int K, int c, int d) {
  return abs(c-d) <= K;
}

int Hack(int K, vector<int> &C, vector<int> &D) {
  int best_c, best_d, total = 0;
  for (int i=0; i<C.size(); i++) {
    best_c = C[i];
    best_d = D[i];
    for (int j=i; j<C.size(); j++) {
      best_c = max(C[j], best_c);
      best_d = max(D[j], best_d);
      if ( just(K, best_c, best_d) ) {
        total++;
      }
    }
  }
  return total;
}

int main() {
  int T, N, K, aux;
  cin >> T;
  vector<int> C, D;
  for (int i=0; i<T; i++) {
    cin >> N;
    cin >> K;
    C.resize(N);
    D.resize(N);
    for (int i=0; i<N; i++) {
      cin >> aux;
      C[i] = aux;
    }
    for (int i=0; i<N; i++) {
      cin >> aux;
      D[i] = aux;
    }
    cout << "Case #" << i+1 << ": " << Hack(K, C, D) << endl;
  }
}
