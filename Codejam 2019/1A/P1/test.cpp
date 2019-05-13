#include <iostream>
using namespace std;

bool goodPos(int i1, int j1, int i2, int j2) {
  if (i2 != -1) {
    if( i1 == i2 || j1 == j2 || (i1 - j1) == (i2 - j2)
       || (i1 + j1) == (i2 + j2) ) {
         cout << "error" << endl;
    }
  }
}


int main() {
  int R, C, T;
  int i1,i2,j1,j2;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> R;
    cin >> C;
    cout << "Case " << R << " " << C << endl;

    i2 = -1;
    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++) {
        cin >> i1 >> j1;
        goodPos(i1, j1, i2, j2);
        i2 = i1;
        j2 = j1;
      }
    }
  }
}
