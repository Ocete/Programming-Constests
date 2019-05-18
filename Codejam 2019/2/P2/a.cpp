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

int Min(vector<int> &v) {
  int min = 0;
  int aux = v[0];
  FOR(i, 1, 5) {
    if (v[i] < aux) {
      min = i;
      aux = v[i];
    }
  }
  return min;
}

int secondMin( vector<int> &v, int min_val) {
   bool found = false;
   int pos = 0;
   int aux = 1000;
   FOR(i, 1, 5) {
     if (v[i] == min_val) {
       if (found) {
         return i;
       }
       found = true;
     } else if (v[i] < aux) {
       pos = i;
       aux = v[i];
     }
   }
   return pos;
}

int Spaces(string str) {
  int ret = 0;
  for (char c : str) {
    if (c == ' ') {
      ret ++;
    }
  }
  return ret;
}

void Hack() {
  int day = 1, V, token = 100, trash;
  V = 1;
  while (day <= 90) {
    cin >> trash;
    cout << V << " " << 100 << endl;
    V++;
    if (V % 16 == 0) {
      V = 1;
    }
    day++;
  }
  vector<int> v (5, -1);
  string str = "";
  FOR (i, 0, 5) {
    cin >> day;
    cout << i + 16 << " " << 0 << endl;
    cin.ignore(100, '\n');
    getline(cin, str);
    day = Spaces(str) + 1;
    v[i] = day;
  }
  // pVector(v);
  // cout << Min(v) << " " << secondMin(v, v[Min(v)]) << endl;
  int min = Min(v);
  FOR (i, 0, 4) {
    cin >> day;
    token = secondMin(v, v[min]);
    v[token]++;
    cout << token+16 << " " <<  100 << endl;
  }
  cin >> day;
  cout << min+16 << " " << 100 << endl;
}

int main() {
  int T;
  cin >> T;
  FOR (i, 0, T) {
    Hack();
  }
}
