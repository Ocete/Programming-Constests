#include <iostream>
using namespace std;

int val(int r, int k) {
  if (r == 1 || r == 2 || k == r)
    return 1;
  if ( k+1 == r )
    return r-1;
}

void P2(int N) {
  int sum = 1;
  cout << "1 1" << endl;
  if ( N == sum )
    return;

  cout << "2 1" << endl;
  sum++;
  if ( N == sum )
    return;

  int r = 3, k = 2;
  while ( sum < N ) {
    if (sum + val(r,k) > N) {
      r--;
    }
    cout << r << " " << k << endl;
    sum += val(r,k);
    r++;
    k++;
  }
}

int main() {
  int T, N;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N;
    cout << "Case #" << i+1 << ": " << endl;
    P2(N);
  }
}
