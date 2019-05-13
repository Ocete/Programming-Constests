#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
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

struct kanji {
  char c1,c2,c3;
};

void readNumber(vector<kanji> &w, int &i, string &line) {
  while( line[i] != ' ' && i < line.size()) {
    kanji k;
    k.c1 = line[i];
    k.c2 = line[i+1];
    k.c3 = line[i+2];
    w.push_back( k );
    i += 3;
  }
  i++;
}

void readTrash(int &i, string &line) {
  while (line[i] != ' ' && i < line.size() ) {
    i++;
  }
  i++;
}

void readLine(vector<kanji> &w1, vector<kanji> &w2, vector<kanji> &w3, string &line) {
  char c1,c2,c3;
  w1.clear();
  w2.clear();
  w3.clear();
  int i=0;
  readNumber(w1, i, line);
  readTrash(i, line);
  readNumber(w2, i, line);
  readTrash(i, line);
  readNumber(w3, i, line);
}

int TransformKanji(kanji k) {
  if (k.c1 == -28 && k.c2 == -72 && k.c3 == -128) {
    return 1;
  } else if (k.c1 == -28 && k.c2 == -70 && k.c3 == -116) {
    return 2;
  } else if (k.c1 == -28 && k.c2 == -72 && k.c3 == -119) {
    return 3;
  } else if (k.c1 == -27 && k.c2 == -101 && k.c3 == -101) {
    return 4;
  } else if (k.c1 == -28 && k.c2 == -70 && k.c3 == -108) {
    return 5;
  } else if (k.c1 == -27 && k.c2 == -123 && k.c3 == -83) {
    return 6;
  } else if (k.c1 == -28 && k.c2 == -72 && k.c3 == -125) {
    return 7;
  } else if (k.c1 == -27 && k.c2 == -123 && k.c3 == -85) {
    return 8;
  } else if (k.c1 == -28 && k.c2 == -71 && k.c3 == -99) {
    return 9;
  } else if (k.c1 == -27 && k.c2 == -115 && k.c3 == -127) {
    return 10;
  } else if (k.c1 == -25 && k.c2 == -103 && k.c3 == -66) {
    return 100;
  } else if (k.c1 == -27 && k.c2 == -115 && k.c3 == -125) {
    return 1000;
  } else if (k.c1 == -28 && k.c2 == -72 && k.c3 == -121) {
    return 10000;
  }
  cout << "Error al transformar kanji" << endl;
  return 0;
}

void TransKanjiVector(vector<kanji> &vk, vector<int> &v) {
  v.resize(vk.size());
  FOR(i, 0, vk.size()) {
    v[i] = TransformKanji( vk[i] );
  }
}

void Combinations(vector<int> &small, vector<int> &big, set<int> &numbers) {
  while ( small.size() < big.size() ) {
    small.push_back(0);
  }
  sort( small.begin(), small.end() );

  do {
    int n = 0, prod;
    FOR (i, 0, small.size()) {

      prod = small[i] * big[i];
      if (small[i] == 1 && (big[i] == 10   ||
                            big[i] == 100  ||
                            big[i] == 1000 )) {
          n = -1;
          break;
      }

      if ( prod == 0 ) {
        if (big[i] == 10000) {
          n = -1;
          break;
        }
        n += small[i] + big[i];
      } else {
        n += prod;
      }
    }
    if (n != -1) {
      numbers.insert(n);
    }
  } while(next_permutation(small.begin(), small.end()));
}

void PossibleNumbers(vector<int> &v, set<int> &numbers) {
  vector<int> small, big;
  FOR(i, 0, v.size()) {
    if( v[i] >= 10 ) {
      big.push_back(v[i]);
    } else {
      small.push_back(v[i]);
    }
  }
  big.push_back(0);
  sort(big.begin(), big.end()) ;

  Combinations(small, big, numbers);
}

void Hack(vector<kanji> &wk1, vector<kanji> &wk2, vector<kanji> &wk3) {
  vector<int> w1, w2, w3;
  set<int> poss1, poss2, poss3;
  unordered_set<int> s;

  TransKanjiVector(wk1, w1);
  TransKanjiVector(wk3, w3);
  TransKanjiVector(wk2, w2);

  PossibleNumbers(w1, poss1);
  PossibleNumbers(w2, poss2);
  PossibleNumbers(w3, poss3);

  for (auto p : poss3) {
    s.insert( p );
  }

  // cout << "Que viene: " << endl;
  // pUnorderedset(poss1);
  // pUnorderedset(poss2);
  // pUnorderedset(poss3);

  for (auto p1 : poss1) {
    for (auto p2 : poss2) {
      if ( s.find(p1 + p2) != s.end() ) {
        cout << p1 << " + " << p2 << " = " << p1+p2 << endl;
        return;
      } else if ( s.find(p1 - p2) != s.end() ) {
        cout << p1 << " - " << p2 << " = " << p1-p2 << endl;
        return;
      } else if ( s.find(p1 * p2) != s.end() ) {
        cout << p1 << " * " << p2 << " = " << p1*p2 << endl;
        return;
      }
    }
  }
}

int main() {
  int T=13, M;
  string line, trash;
  vector<kanji> w1, w2, w3;

  cin >> T;
  getline(cin, trash);
  for (int i=0; i<T; i++) {
    getline(cin, line);
    readLine(w1, w2, w3, line);
    cout << "Case #" << i+1 << ": ";
    Hack(w1, w2, w3);
  }
}
