#include <iostream>
using namespace std;

void Hack(int N) {
  int limit = 2*N-2;
  char c;
  for (int i=0; i<limit; i++) {
    cin >> c;
    if ( c == 'S' ) {
      cout << 'E';
    } else {
      cout << 'S';
    }
  }
}

int main() {
  int T, N, n1, n2;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N;
    cout << "Case #" << i+1 << ": ";
    Hack(N);
    cout << endl;
  }
}
