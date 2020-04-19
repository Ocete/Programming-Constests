#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void swap (int &x, int &y) {
  int aux = x;
  x = y;
  y = aux;
}

bool onlyOneOdd(int x, int y) {
  return (x & 1) != (y & 1);
}

void move(stringstream &ss, bool forward, bool movement_inverted) {
  if (forward && !movement_inverted) {
    ss << 'W';
  } else if (!forward && !movement_inverted) {
    ss << 'E';
  } else if (forward && movement_inverted) {
    ss << 'S';
  } else {
    ss << 'N';
  }
}

void invertMovement(string &str, bool invert_x, bool invert_y) {
  for (int i=0; i<str.length(); i++) {
    if (invert_x && str[i] == 'E') {
      str[i] = 'W';
    } else if (invert_x && str[i] == 'W') {
      str[i] = 'E';
    } else if (invert_y && str[i] == 'N') {
      str[i] = 'S';
    } else if (invert_y && str[i] == 'S') {
      str[i] = 'N';
    }
  }
}

string P1(int x, int y) {
  bool invert_x = x < 0, invert_y = y < 0, done;
  stringstream ss;
  int base;

  bool movement_inverted = false;

  if (invert_x)
    x = abs(x);
  if (invert_y)
    y = abs(y);

  while (x != 0 || y != 0) {
    if ( !onlyOneOdd(x,y) ) {
      return "IMPOSSIBLE";
    }

    if (y&1) {
      swap(x,y);
      movement_inverted = !movement_inverted;
    }

    done = false;
    base = 2;
    while (!done) {
      //cout << "2: " << x << "-" << y << "-" << base << endl;

      if ( (y == 0) ) {
        done = true;
        if ( (x == 1) || (x&base)) {
          x--;
          move(ss, false, movement_inverted);
        } else {
          x++;
          move(ss, true, movement_inverted);
        }
      } else {
        if ( (!(x&base) && (y&base)) ) {
          x--;
          move(ss, false, movement_inverted);
          done = true;
        } else if ( (x&base) == (y&base) ) {
          x++;
          move(ss, true, movement_inverted);
          done = true;
        } else if (x&base) {
          x--;
          move(ss, false, movement_inverted);
          done = true;
        }
      }
    }

    x /= 2;
    y /= 2;
  }

  string str = ss.str();
  invertMovement(str, invert_x, invert_y);
  return str;
}

int main() {
  int T, x, y;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> x;
    cin >> y;
    cout << "Case #" << i+1 << ": " << P1(x, y) << endl;
  }
}
