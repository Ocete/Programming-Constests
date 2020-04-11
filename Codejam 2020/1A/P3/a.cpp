#include <iostream>
#include <vector>
using namespace std;

void readMatrix(int R, int C, vector<vector<int>> &mat) {
  int aux;
  vector<int> v_aux = vector<int> (C, 0);
  mat = vector<vector<int>> (R, v_aux);
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      cin >> aux;
      mat[i][j] = aux;
    }
  }
}

int countPoints(int R, int C, vector<vector<int>> &mat) {
  int aux = 0;
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      aux += mat[i][j];
    }
  }
  return aux;
}

bool eliminateOne(vector<vector<int>> &mat, const int x, const int y, int R, int C) {
  if (mat[x][y] == 0)
    return false;

  int N = 0;
  double sum = 0;
  int i, j;

  i = x-1;
  j = y;
  while (i >= 0 && mat[i][j] == 0) {
    i--;
  }
  if ( i >= 0 ) {
    sum += mat[i][j];
    N++;
  }

  i = x+1;
  j = y;
  while (i < R && mat[i][j] == 0) {
    i++;
  }
  if ( i < R ) {
    sum += mat[i][j];
    N++;
  }

  i = x;
  j = y-1;
  while (j >= 0 && mat[i][j] == 0 ) {
    j--;
  }
  if ( j >= 0 ) {
    sum += mat[i][j];
    N++;
  }

  i = x;
  j = y+1;
  while (j < C && mat[i][j] == 0 ) {
    j++;
  }
  if ( j < C ) {
    sum += mat[i][j];
    N++;
  }
  return (N > 0) && (mat[x][y]*1.0 < sum/N);
}

bool eliminate(int R, int C, vector<vector<int>> &mat) {
  vector<vector<int>> old_mat(mat);
  int result = 0;
  bool elimination;
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      elimination = eliminateOne(old_mat, i, j, R, C);
      if (elimination) {
        mat[i][j] = 0;
        result++;
      }
    }
  }
  return result > 0;
}

int P3(int R, int C, vector<vector<int>> &mat) {
  int total_points = 0;
  do {
    total_points += countPoints(R, C, mat);
  } while ( eliminate(R, C, mat) );
  return total_points;
}

int main() {
  int T, R, C;
  vector<vector<int>> mat;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> R;
    cin >> C;
    mat.clear();
    readMatrix(R, C, mat);
    cout << "Case #" << i+1 << ": " << P3(R, C, mat) << endl;
  }
}
