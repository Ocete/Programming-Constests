#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define FOR(i,A,B) for(int i=A; i<B; i++)

template <class T>
void pVector(vector<T> &v) {
  FOR(i,0,v.size()) {
    cout << v[i] << " ";
  }
  cout << endl;
}

template <class T>
void pMatrix(vector<vector<T> > &m) {
  FOR(i,0,m.size()) {
    pVector(m[i]);
  }
}

// -----------------------------------------------


void Hack(int N, int M) {
  int n = N/2, m = M/2;
  if ( N % 2 == 1) {
    n++;
  }
  if (M % 2 == 1) {
    m++;
  }
  cout << n + m << endl;
}

int main() {
  int T, N, M;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N >> M;
    cout << "Case #" << i+1 << ": ";
    Hack(N, M);
  }
}
