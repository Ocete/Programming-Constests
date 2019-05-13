#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cmath>
using namespace std;
#define FOR(i,A,B) for(int i=A; i<B; i++)

template <class T>
void readVector (vector<T> &v, int tam) {
  T aux;
  v.resize(tam);
  FOR (i, 0, tam) {
    cin >> aux;
    v[i] = aux;
  }
}

template <class T>
void pVector(vector<T> &v) {
  FOR(i,0,v.size()) {
    cout << v[i] << " ";
  }
  cout << endl;
}

template <class T>
void pUnorderedset(set<T> &s) {
  for (auto p : s) {
    cout << p << " ";
  }
  cout << endl;
}

template <class T>
void pMatrix(vector<vector<T> > &m) {
  FOR(i,0,m.size()) {
    cout << i << " -> ";
    pVector(m[i]);
  }
}

template <class A, class B>
void pMap(map<A,B> &m) {
  auto it = m.begin();
  for ( ; it != m.end(); it++) {
    cout << it->first << " -> " < it->second << endl;
  }
}

template <class A, class B>
void pPair(pair<A,B> &p) {
  cout << "(" << p.first << " , " << p.second  << ")";
}

// -----------------------------------------------

// bool operator < (const state &s1, const state &s2) {
//
// }

string Hack( vector<string> &enem ) {

  vector<bool> alive (enem.size(), true), poss;
  string sol;
  char c, your_c;
  bool p,r,s;

  int i=0;
  while (true) {
    p = true;
    s = true;
    r = true;
    FOR (j, 0, enem.size()) {
      if ( alive[j] ) {
        c = enem[j][ i % enem[j].size()];
        if (c == 'P') {
          r = false;
        } else if( c == 'R') {
          s = false;
        } else if ( c == 'S') {
          p = false;
        }
      }
    }

    if ( !p && !r && !s ) {
      return "IMPOSSIBLE";
    }

    if ( p && s ) {
      sol.push_back('S');
      return sol;
    } else if ( p && r ) {
      sol.push_back('P');
      return sol;
    } else if (r && s) {
      sol.push_back('R');
      return sol;
    } else if ( p ) {
      sol.push_back('P');
    } else if ( s ) {
      sol.push_back('S');
    } else if ( r ) {
      sol.push_back ('R');
    }

    your_c = sol [ sol.length()-1 ];
    FOR (j, 0, enem.size()) {
      c = enem[j][ i % enem[j].size()];
      if (c == 'P' && your_c == 'S') {
        alive[j] = false;
      } else if( c == 'R' && your_c == 'P') {
        alive[j] = false;
      } else if ( c == 'S' && your_c == 'R') {
        alive[j] = false;
      }
    }
    i++;
  }
}

int main() {
  int T, A;
  cin >> T;
  string aux;
  vector<string> v;
  FOR (i, 0, T) {
    cin >> A;
    readVector(v, A);
    cout << "Case #" << i+1 << ": " << Hack(v) << endl;
  }
}
