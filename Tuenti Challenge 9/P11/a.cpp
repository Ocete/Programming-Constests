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

struct state{
  int hour;
  int planet;
  vector<bool> visited;
  double fuel;
};

bool operator < (const state &s1, const state &s2) {
  if ( s1.hour < s2.hour || ( s1.hour == s2.hour && s1.planet < s2.planet) ||
      (s1.hour == s2.hour && s1.planet == s2.planet && s1.fuel < s2.fuel) ) {
    return true;
  }

  bool check_v = s1.hour == s2.hour &&
                s1.planet == s2.planet &&
                s1.fuel == s2.fuel;

  if (!check_v) {
    return false;
  }

  int i=0;
  while (i<s1.visited.size()) {
    if (s1.visited[i] && !s2.visited[i]) {
      return true;
    } else if (!s1.visited[i] && s2.visited[i]) {
      return false;
    }
    i++;
  }

  cout << "Error in comparison operator" << endl;
  return true;
}

double PI = 3.14;
map<state, int> mem;
vector<double> d, r, per;
vector<int> mat;
int Capacity;


double radians(int i, int hour) {
  return r[i] + (double)2*PI*hour/(double)per[i];
}

double distance(int from, int to, int hour) {
  if ( min(from,to) == -1) {
    return d[ max(from,to) ];
  }
  double rad1 = radians(from, hour), rad2 = radians(to, hour);
  return sqrt( d[from]*d[from] + d[to]*d[to] - 2*d[from]*d[to]*cos(rad1-rad2));
}

void pState(state s) {
  cout << "h: " << s.hour << " - planet:" << s.planet << " - fuel: " << s.fuel << endl;
  cout << "Visited: ";
  pVector(s.visited);
}

int Explore(int cargo, const state &s) {
  pState(s);
  cout << "Cargo: " << cargo << endl << endl;;
  if (s.planet == -1) {
    if (cargo > 0) {
      return cargo;
    }
  } else if ( s.fuel < d[ s.planet ] ) {
    return 0;
  }

  if (s.planet != -1) {
    cargo += mat[ s.planet ];
  }

  state new_s;
  new_s.hour = s.hour+6;
  new_s.visited = s.visited;
  new_s.fuel = s.fuel;
  int best_delivery = cargo;
  double current_d;
  FOR (i, 0, d.size()) {
    if ( !s.visited[i] && ( Capacity > cargo + mat[i] ) ) {
      current_d = distance(s.planet, i, s.hour);
      new_s.visited[i] = true;
      new_s.planet = i;
      new_s.fuel -= current_d;
      best_delivery = max( best_delivery, Explore(cargo, new_s) );
      new_s.fuel += current_d;
      new_s.visited[i] = false;
    }
  }
  return best_delivery;
}

int Hack( int R ) {
  mem.clear();
  state s;
  vector<bool> visited (d.size(), false);
  s.hour = 0;
  s.planet = -1;
  s.fuel = R;
  s.visited = visited;

  cout << "Capacity: " << Capacity  << endl;

  return Explore(0, s);
}

int main() {
  int T, M, C, R;
  cin >> T;
  FOR (i, 0, T) {
    cin >> M;
    readVector(d, M);
    readVector(r, M);
    readVector(per, M);
    readVector(mat, M);
    cin >> Capacity >> R;
    cout << "Case #" << i+1 << ": " << Hack(R) << endl;
  }
}
