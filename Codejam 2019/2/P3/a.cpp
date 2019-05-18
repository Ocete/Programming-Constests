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

  bool isValid(vector<pair<int,int> > &v, int c, int j) {
    FOR(i, 0, v.size()-1) {
      int val = v[i+1].first * c + v[i+1].second * j - v[i].first * c - v[i].second * j;
      if (val <= 0) {
        return false;
      }
  }
    return true;
  }

  void Hack(vector<pair<int,int> > &v) {
    FOR (c, 1, 10000) {
      FOR (j, 1, 10000) {
        if ( isValid(v,c,j) ) {
          cout << c << " " << j << endl;
          return;
        }
      }
    }
    cout << "IMPOSSIBLE" << endl;
  }

  int main() {
    int T,N;
    int a,b;
    vector<pair<int,int> > v;
    cin >> T;
    FOR (i, 0, T) {
      cin >> N;
      v.clear();
      FOR (j, 0, N) {
        cin >> a >> b;
        v.push_back(pair<int,int> (a,b));
      }
      cout << "Case #" << i+1 << ": ";
      Hack(v);
    }
  }
