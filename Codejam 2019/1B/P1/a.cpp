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

struct person{
  int x,y;
  char dir;
};

void rellena(person p, vector<int> &hor, vector<int> &ver) {
  int Q = hor.size();

  if ( p.dir == 'N' ) {
    FOR(i, p.y+1, Q) {
      ver[i]++;
    }
  } else if ( p.dir == 'S' ) {
    FOR(i, 0, p.y) {
      ver[i]++;
    }
  } else  if ( p.dir == 'E' ) {
    FOR(i, p.x+1, Q) {
      hor[i]++;
    }
  } else {
    FOR(i, 0, p.x) {
      hor[i]++;
    }
  }
}

void Hack(int Q, vector<person> &people) {
  vector<int> hor (Q+1, 0), ver (Q+1, 0);

  for (int i=0; i<people.size(); i++) {
    rellena(people[i], hor, ver);
  }

  int max_hor = -1, max_ver = -1, min_i = 0, min_j = 0;
  FOR(i, 0, hor.size() ) {
    if (hor[i] > max_hor) {
      max_hor = hor[i];
      min_i = i;
    }
    if (ver[i] > max_ver) {
      max_ver = ver[i];
      min_j = i;
    }
  }
  cout << min_i << " " << min_j << endl;
}

int main() {
  int T, P, Q, xaux, yaux;
  person p;
  char c;
  cin >> T;
  vector<person> people;
  for (int i=0; i<T; i++) {
    cin >> P;
    cin >> Q;
    people.resize(P);
    for (int i=0; i<P; i++) {
      cin >> xaux >> yaux >> c;
      p.x = xaux;
      p.y = yaux;
      p.dir = c;
      people[i] = p;
    }

    cout << "Case #" << i+1 << ": ";
    Hack(Q, people);
  }
}
