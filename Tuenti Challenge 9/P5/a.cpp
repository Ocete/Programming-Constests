#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
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

vector<vector<char> > maquina = { {'1','2','3','4','5','6','7','8','9','0'},
                                  {'Q','W','E','R','T','Y','U','I','O','P'},
                                  {'A','S','D','F','G','H','J','K','L',';'},
                                  {'Z','X','C','V','B','N','M',',','.','-'} };
map<char, pair<int,int> > dict;

void mapea() {
  FOR(y,0,maquina.size() ) {
    FOR(x,0,maquina[0].size() ) {
      dict[ maquina[y][x] ] = pair<int,int>(y,x);
    }
  }
}

pair<int,int> charToPos(char c) {
  return dict[c];
}

char posToChar(pair<int,int> &p) {
  return maquina[p.first][p.second];
}

void Hack(char C, string &mess) {
  pair<int,int> pC = charToPos(C),
                pFirma = charToPos( mess[mess.length()-1] );
  pair<int,int> offset = pair<int,int>(pC.first - pFirma.first,
                                      pC.second - pFirma.second);
  FOR(i, 0, mess.length()) {
    if (mess[i] != ' ') {
      char a = mess[i];
      pFirma = charToPos(a);
      pFirma.first = (pFirma.first + offset.first + 4) % 4;
      pFirma.second = (pFirma.second + offset.second + 10) % 10;
      a = posToChar(pFirma);
      mess[i] = a;
    }
  }
  cout << mess << endl;
}

int main() {
  int T;
  string mess, trash;
  char C;

  mapea();

  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> C;
    getline(cin, trash);
    getline(cin, mess);

    cout << "Case #" << i+1 << ": " ;
    Hack(C, mess);
  }
}
