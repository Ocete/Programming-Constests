#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> // exit
using namespace std;

int middle(int a, int b) {
  return (a+b)/2;
}

int side(int max, int min) {
  int side = (max-min)/4;
  return side == 0 ? 1 : side;
}

void P2(int R) {
  int min_x=-50, min_y=-50, max_x=50, max_y=50, aux;
  bool no_stop = true;
  string str;
  int tries = 0;

  while (no_stop) {
    if (tries == 299) {
      exit(EXIT_FAILURE);
    }
    tries++;

    if (min_x != max_x) {
      aux = middle(min_x, max_x) + side(max_x, min_x);
      cout << R-50+aux << " " << middle(min_y, max_y) << endl;
      cin >> str;
      if ( str == "HIT" ) {
        min_x += side(max_x, min_x);
      } else if ( str == "MISS" ) {
        //cout << "Changes: " << max_x << " " << min_x << " " << side(max_x, min_x) << endl;
        max_x -= side(max_x, min_x);
      } else {
        exit(EXIT_SUCCESS);
      }
    }

    if (min_y != max_y) {
      aux = middle(min_y, max_y) + side(max_y, min_y);
      cout << middle(min_x, max_x) << " " << R-50+aux << endl;
      cin >> str;
      if ( str == "HIT" ) {
        min_y += side(max_y, min_y);
      } else if ( str == "MISS" ) {
        max_y -= side(max_y, min_y);
      } else {
        exit(EXIT_SUCCESS);
      }
    }

    if ( min_x == max_x && min_y == max_y) {
      no_stop = false;
    }
  }

  cout << min_x << " " << min_y << endl;
  cin >> str;
  if (str != "CENTER") {
    vector<int> vy = {0,0,-1,1};
    vector<int> vx= {-1,1,0,0};
    for (int i=0; i<4; i++) {
      for (int j=0; j<4; j++) {
        cout << min_x+vx[i] << " " << min_y+vy[j] << endl;
        cin >> str;
        if (str == "CENTER")
          return;
      }
    }
    exit(EXIT_SUCCESS);
  }
}

int main() {
  int T, R;
  cin >> T;
  cin >> R;
  cin >> R;
  for (int i=0; i<T; i++) {
    P2(R);
  }
}
