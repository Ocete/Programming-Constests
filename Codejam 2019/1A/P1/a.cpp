#include <iostream>
using namespace std;

bool isPossible(int R, int C) {
  int m = min(R,C), M = max (R,C);
  return M >= 5 || ( M == 4 && m >= 3);
}

void printPair(int i, int j) {
  cout << i+1 << " " << j+1 << endl;
}

bool goodPos(pair<int,int> p, int ki, int kj) {
  return p.first != ki && p.second != kj && (p.first - p.second) != (ki - kj)
     && (p.first + p.second) != (ki + kj);
}

void Hack(int R, int C) {
  bool p = isPossible(R,C);
  if ( p ) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  int paridad = R % 2, kj;
  int max_i = paridad == 0 ? R : R - 3;
  pair<int,int> last (0,0);

  // Caso pocas columnas
  if (C == 2) {
    for (int i=0; i<R; i++) {
      printPair((i+2)%R, 1);
      printPair(i, 0);
    }
  } else if ( C == 3 ) {
    for (int i=0; i<R; i++) {
      printPair(i, 0);
      printPair((i+2)%R, 1);
      printPair(i, 2);
    }
  } else if (C == 4 && R == 4) {
    for (int i=0; i<3; i++) {
      printPair(i, 0);
      printPair((i+2)%R, 1);
      printPair(i, 2);
      printPair((i+2)%R, 3);
    }
    printPair(1, 1);
    printPair(2, 3);
    printPair(3, 1);
    printPair(0, 3);
  } else {
    for (int i=0; i<max_i; i+=2) {
      kj = 0;
      if ( !goodPos(last, i+1, kj+2) ) {
        kj++;
      }
      for (int j=0; j<C; j++) {
        printPair(i+1, (kj+2)%C);
        printPair(i, (kj)%C);
        kj++;
        last = pair<int,int>(i,j);
      }
    }

    if ( paridad == 1 ) {
      kj = 0;
      if ( !goodPos(last, max_i, kj) ) {
        kj++;
      }
      for (int j=0; j<C; j++) {
        printPair(max_i, (kj)%C);
        printPair(max_i+1, (kj+2)%C);
        printPair(max_i+2, (kj)%C);
        kj++;
      }
    }
  }
}

int main() {
  int T, R, C;
  cin >> T;
  //cout << T << endl;
  for (int i=0; i<T; i++) {
    cin >> R;
    cin >> C;
    cout << "Case #" << i+1 << ": ";
    //cout << R << " " << C << endl;
    Hack(R,C);
  }
}
