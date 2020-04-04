#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

char itoc(int i) {
  return '0' + i;
}

string toString(vector<int> v) {
  stringstream ss;
  for (int i=0; i<v.size(); i++)
    ss << itoc( v[i] );
  return ss.str();
}

void P4(int B) {
  vector<int> v(B, 0);
  int read;

  for (int i=0; i<B; i++) {
    cout << i;
    cin >> read;
    v[i] = read;
  }
  cout << toString(v);

  char c;
  cin >> c;
  if (c == 'N')
    exit(1);
}

int main() {
  int T, B;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> B;
    P4(B);
  }
}
