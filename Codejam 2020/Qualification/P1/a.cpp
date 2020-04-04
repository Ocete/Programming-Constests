#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void readMatrix(int N, vector<vector<int>> &mat) {
  int aux;
  vector<int> v_aux = vector<int> (N, 0);
  mat = vector<vector<int>> (N, v_aux);
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> aux;
      mat[i][j] = aux;
    }
  }
}

void P1(vector<vector<int>> &mat, int T) {
  int trace = 0, N = mat.size();
  for (int i=0; i<N; i++) {
    trace += mat[i][i];
  }

  int n_rows = 0, n_col = 0;
  unordered_set<int> s;
  for (int i=0; i<N; i++) {
    s.clear();
    for (int j=0; j<N; j++) {
      s.insert(mat[i][j]);
    }
    if (s.size() != N)
      n_rows++;
  }
  for (int i=0; i<N; i++) {
    s.clear();
    for (int j=0; j<N; j++) {
      s.insert(mat[j][i]);
    }
    if (s.size() != N)
      n_col++;
  }

  cout << "Case #" << T+1 << ": " << trace << " " << n_rows << " " << n_col << endl;
}

int main() {
  int T, N, i;
  vector<vector<int>> mat;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N;
    readMatrix(N, mat);
    P1(mat, i);
  }
}
