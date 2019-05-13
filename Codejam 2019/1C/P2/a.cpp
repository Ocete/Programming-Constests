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

char obtainPoss (int poss, vector<int> count, int total) {
  char c;
  FOR(i, 0, 120) {
    cout << (5*i) +(poss+1) << endl;
    cin >> c;
    count[c-'A']++;
    if (count[c-'A'] == 24) {
      total++;
    }
    if (total == 4) {
      break;
    }
  }

  for (int i=0; i<5; i++) {
    if (count[i] < 24) {
      return i+'A';
    }
  }
}

string Hack() {
  string sol;
  char c;
  vector<int> v = {0,0,0,0,0};

  FOR(i, 0, 4) {
    c = obtainPoss(i, v, i);
    sol.push_back(c);
    v[ c-'A'] = 30;
  }

  FOR (a, 0, 5) {
    if (v[a] != 30) {
      sol.push_back(a+'A');
    }
  }

  return sol;
}

int main() {
  int T, F;
  cin >> T >> F;
  FOR (i, 0, T) {
    cout << Hack() << endl;
  }
}
