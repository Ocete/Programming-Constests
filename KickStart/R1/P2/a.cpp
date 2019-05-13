#include <iostream>
#include <vector>
using namespace std;

template <class T>
void printMat (vector<vector<T> > &mat) {
  for (unsigned i=0; i<mat.size(); i++) {
    for (unsigned j=0; j<mat.size(); j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}


int maxValue(vector<vector<int>> &m) {
  int R = m.size();
  int C = m[0].size();
  int maxVal = 0;
  for (int j=0; j<R; j++) {
    for (int k=0; k<C; k++) {
      maxVal = max(maxVal, m[j][k]);
    }
  }
  return maxVal;
}

void expand(vector<vector<bool>> &m, vector<vector<int>> &dist, int i, int j, int current_dist) {
  if (i <0 || i>= m.size() || j<0 || j>=m[0].size() || dist[i][j] < current_dist) {
    return;
  }

  if (m[i][j] && current_dist > 0) {
    return;
  }

  dist[i][j] = current_dist;

  expand(m, dist, i+1, j, current_dist+1);
  expand(m, dist, i-1, j, current_dist+1);
  expand(m, dist, i, j+1, current_dist+1);
  expand(m, dist, i, j-1, current_dist+1);
}

void computeDistances(vector<vector<bool>> &m, vector<vector<int>> &dist) {
  int R = m.size();
  int C = m[0].size();
  for (int j=0; j<R; j++) {
    for (int k=0; k<C; k++) {
      if (m[j][k]) {
        expand(m, dist, j, k, 0);
      }
    }
  }
}

int placement(vector<vector<bool>> m, vector<vector<int>> dist, int i, int j) {
  m[i][j] = true;
  expand(m, dist, i, j, 0);
  return maxValue(dist);
}

int Hack(int R, int C, vector<vector<bool>> &m) {
  vector<int> v (C, R+C+1);
  vector<vector<int>> dist (R, v);

  computeDistances(m, dist);

  int maxi = maxValue(dist);
  int best_sol = maxi;
  for (int j=0; j<R; j++) {
    for (int k=0; k<C; k++) {
      /*if (dist[j][k] == maxi) {
        best_sol = min(best_sol, placement(m, dist, j, k) );
      }*/
      if (dist[j][k] != 0) {
        best_sol = min(best_sol, placement(m, dist, j, k) );
      }
    }
  }

  return best_sol;
}

int main() {
  int T, R,C;
  char c;
  vector<vector<bool>> m;
  vector<bool> v;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> R >> C;
    m.clear();
    v.clear();
    v = vector<bool> (C, false);
    m = vector<vector<bool> > (R, v);
    for (int j=0; j<R; j++) {
      for (int k=0; k<C; k++) {
        cin >> c;
        m[j][k] = c == '1';
      }
    }
    cout << "Case #" << i+1 << ": " << Hack(R, C, m) <<endl;
  }
}
