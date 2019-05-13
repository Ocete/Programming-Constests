#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <class T>
void printVector (vector<T> &v) {
  for (unsigned i=0; i<v.size(); i++) {
      cout << v[i] << " ";
  }
  cout << endl;
}


int maxValue(vector<int> &v, int start) {
  int maxVal = 0;
  for (int i=start; i<v.size(); i++) {
    maxVal = max(maxVal, v[i]);
  }
  return maxVal;
}

int Hack(int N, int P, vector<int> &v) {
  vector<int> acumm (maxValue(v,0)+1, 0);

  for (int i=0; i<v.size(); i++) {
    acumm[ v[i] ]++;
  }

  int min_hours = P*100000;
  int students = 0;
  for (int i=0; i<acumm.size(); i++) {
    if (students < P) {
      students += acumm[i];
    }
    if (students >= P && acumm[i] > 0) {
      int current_h = 0, current_std = acumm[i], diff;
      int j = i-1;
      while (current_std < P) {
        diff = min(acumm[j], P - current_std);
        current_h += diff*(i-j);
        current_std += diff;
        j--;
      }
      min_hours = min(min_hours, current_h);
    }
  }
  return min_hours  ;
}

int main() {
  int T, N, P;
  int aux;
  vector<int> v;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N >> P;
    v.clear();
    v.resize(N);
    for (int j=0; j<N; j++) {
      cin >> aux;
      v[j] = aux;
    }
    cout << "Case #" << i+1 << ": " << Hack(N, P, v) <<endl;
  }
}
