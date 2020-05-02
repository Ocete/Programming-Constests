#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int dist(int x, int y) {
  return abs(x) + abs(y);
}

void update(int &x, int &y, char move) {
  if (move == 'N') {
    y++;
  } else if (move == 'S') {
    y--;
  } else if (move == 'E') {
    x++;
  } else if (move == 'W') {
    x--;
  }
}


void P1(int x, int y, string tour) {
  int time, d;
  for (time=0; time < tour.length(); time++ ){
    update(x, y, tour[time]);
    d = dist(x,y);
    if (time+1 >= d) {
      cout << time+1 << endl;
      return;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

int main() {
  int T, x, y;
  string str;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> x;
    cin >> y;
    cin >> str;
    cout << "Case #" << i+1 << ": ";
    P1(x, y, str);
  }
}
