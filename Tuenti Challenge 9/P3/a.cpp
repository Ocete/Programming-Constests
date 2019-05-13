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

// -----------------------------------------------

void updateSize(int &W, int &H, char c) {
  if (c == 'T' || c == 'B') {
    H *= 2;
  } else if (c == 'L' || c == 'R') {
    W *= 2;
  } else {
    cout << "Error 2" << endl;
    exit;
  }
}

void folding(char c, int j, int W, int H, vector<pair<int,int> > &P) {
  pair<int,int> p = P[j], p2 = p;

  if (c == 'T') {
    p2.second = H - p.second - 1;
    p.second += H;
  } else if (c == 'B') {
    p2.second = 2*H - p.second - 1;
  } else if (c == 'L') {
    p2.first = W - p.first - 1;
    p.first += W;
  } else if (c == 'R') {
    p2.first = 2*W - p.first - 1;
  } else {
    cout << "Error" << endl;
    exit;
  }

  P[j] = p;
  P.push_back(p2);
}

bool operator < (const pair<int,int> &p1, const pair<int,int> &p2) {
  return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
}

void Hack(int W, int H, vector<char> &F, vector<pair<int,int> > &P) {
  int nP = P.size();

  FOR(i, 0, F.size()) {
    nP = P.size();
    FOR(j, 0, nP) {
      folding(F[i], j, W, H, P);
    }
    updateSize(W, H, F[i]);

  }

  sort( P.begin(), P.end() );
  FOR(i, 0, P.size()) {
    cout << P[i].first << " " << P[i].second << endl;
  }
}

int main() {
  int T, W, H, nP, nF, a1, a2;
  vector<pair<int,int> > P;
  vector<char> F;
  char c;

  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> W >> H >> nF >> nP;

    F.resize(nF);
    P.resize(nP);
    FOR (i, 0, nF) {
      cin >> c;
      F[i] = c;
    }
    FOR (i, 0, nP) {
      cin >> a1 >> a2;
      P[i] = pair<int,int>(a1,a2);
    }
    cout << "Case #" << i+1 << ":" << endl;
    Hack(W, H, F, P);
  }
}
