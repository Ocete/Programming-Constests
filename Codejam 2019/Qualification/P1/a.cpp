#include <iostream>
using namespace std;

void Hack(int N, int &n1, int &n2) {

  n1 = 0;
  n2 = 0;
  int aux, base = 1;

  while ( N > 0 ) {
    aux = N % 10;
    N = N/10;
    if (aux == 4) {
      n1 += 2*base;
      n2 += 2*base;
    } else {
      n1 += aux*base;
    }
    base *= 10;
  }
}

int main() {
  int T, N, n1, n2;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N;
    Hack(N, n1,n2);
    cout << "Case #" << i+1 << ": " << n1 << " " << n2 << endl;
  }
}
