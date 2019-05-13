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

int R, C;

bool expand( vector<vector<char> > &next, int i, int j, int form) {
  if ( i < 0 || i >= R || j < 0 || j >= C) {
    return true;
  }
  if ( next[i][j] == '#' ) {
    return false;
  } else if ( next[i][j] == 'b') {
    return true;
  }
  next[i][j] = 'b';
  bool result;
  if ( form == 'H') {
    result = expand(next, i, j+1, form) && expand(next, i, j-1, form);
  } else if (form == 'V') {
    result = expand(next, i+1, j, form) && expand(next, i-1, j, form);
  }
  return result;
}

bool Recursive( vector<vector<char> > &mat, char turn ) {
  vector<vector<char> > next;
  bool result;
  vector<char> poss = {'H', 'V'};
  char opp_turn = turn == 'B' ? 'T' : 'B';
  FOR( i, 0, R) {
    FOR( j, 0, C) {
      if ( mat[i][j] == '.' ) {
        for (char c : poss) {
          next = mat;
          if ( expand(next, i, j, c) ) {
            result = Recursive(next, opp_turn);
            if ( result && turn == 'B' ) {
              return true;
            }
            if ( !result && turn == 'T' ) {
              return false;
            }
          }
        }
      }
    }
  }
  return turn  == 'T';
}

int Hack( vector<vector<char> > &mat ) {
  vector<vector<char> > next;
  int result = 0;

  vector<char> poss = {'H', 'V'};

  FOR( i, 0, R) {
    FOR( j, 0, C) {
      for (char c : poss) {
        next = mat;
        if ( expand(next, i, j, c) ) {
          if ( Recursive(next, 'T') ) {
            result++;
          }
        }
      }
    }
  }
  return result;
}

int main() {
  int T;
  cin >> T;
  vector<char> v;
  char c;
  FOR (i, 0, T) {
    vector<vector<char> > mat;
    cin >> R >> C;
    FOR(j, 0, R) {
      vector<char> v;
      FOR(k, 0, C) {
        cin >> c;
        v.push_back(c);
      }
      mat.push_back(v);
    }
    cout << "Case #" << i+1 << ": " << Hack(mat) << endl;
  }
}
