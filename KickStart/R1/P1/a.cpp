#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void printVector (vector<T> &v) {
  for (unsigned i=0; i<v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int asignar(pair<int,int> Qi, vector<bool> &asientos_usados) {
  int k = 0;
  for (int i=Qi.first; i<=Qi.second; i++){
    if( !asientos_usados[i] ) {
      k++;
      asientos_usados[i] = true;
    }
  }
  return k;
}

bool operator < (pair<int,int> &p1, pair<int,int> &p2) {
  return (p1.second - p1.first) < (p2.second - p2.first);
}

int asignarRecursivo(int n_asignaciones, int ultima_asignacion, vector<bool> Qi_asignados,
    vector<bool> asientos_usados, vector<pair<int,int> > &Q, int max_value) {

  int k = asignar(Q[ultima_asignacion], asientos_usados), k2 = 0;
  Qi_asignados[ultima_asignacion] = true;


  sort(Q.begin(), Q.end());

  /*  cout << "Asignacion: " << ultima_asignacion  << " " << k << endl;
    printVector(asientos_usados);
    printVector(Qi_asignados);
*/
  if (k == 0 || n_asignaciones == Q.size()) {
    return k;
  }

  for (int i=0; i<Qi_asignados.size(); i++) {
    if ( !Qi_asignados[i] ) {
      k2 = max (k2 , asignarRecursivo(n_asignaciones+1, i, Qi_asignados, asientos_usados, Q, max_value) );
      if (k2 >= max_value) {
        break;
      }
    }
  }
  return min(k,k2);
}

int pisados(pair<int,int> &p1, pair<int,int> &p2) {
  int interseccion = min(p1.second, p2.second) - max(p1.first, p2.first) + 1;

  if (interseccion <= 0) {
    interseccion = 0;
  }

  int s1 = p1.second - p1.first + 1, s2 = p2.second - p2.first + 1;
  int attemp1 = min(s1-interseccion,s2), attemp2 = min(s2-interseccion,s1);
  return max(attemp1, attemp2);
}

int computeBound(int N, int Q, vector<pair<int,int> > &Qs) {
  int bound = N/Q;
  for (int i=0; i<Qs.size(); i++)  {
    for (int j=0; j<Qs.size(); j++)  {
      if (i != j) {
        bound = min (bound, pisados(Qs[i],Qs[j]));
      }
    }
  }
  return bound;
}

int Hack(int N, int Q, vector<pair<int,int> > &Qs) {
  vector<bool> Qi_asignados (Q, false), asientos_usados (N+1, false);
  int k = 0;
  int bound = computeBound(N, Q, Qs);
  for (int i=0; i<Qi_asignados.size(); i++) {
      k = max (k , asignarRecursivo(1, i, Qi_asignados, asientos_usados, Qs, bound) );
  }
  return k;
}

int main() {
  int T, N, Q, aux1, aux2;
  vector<pair<int,int> > v;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N;
    cin >> Q;
    v.clear();
    v.resize(Q);
    for (int j=0; j<Q; j++) {
      cin >> aux1 >> aux2;
      v[j] = pair<int,int> (aux1, aux2);
    }
    cout << "Case #" << i+1 << ": " << Hack(N, Q, v) <<endl;
  }
}
