#include <iostream>
#include <vector>
using namespace std;

template <class T>
void printVector (vector<T> &v) {
  for (unsigned i=0; i<v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int ctoi(char c) {
  return c - 'A';
}

bool atMostOneTrue(vector<bool> &v) {
  int total_trues = 0;
  for (int i=0; i<v.size() && total_trues<2; i++) {
    if (v[i]) {
      total_trues++;
    }
  }
  return total_trues<2;
}

bool palindrome(vector<char> &str, int init, int end) {
  vector<bool> v ('z'-'a'+1, false);
  for (int i=init; i<=end; i++) {
    v[ ctoi(str[i]) ] = !v[ ctoi(str[i]) ];
  }
  return atMostOneTrue(v);
}

int Hack(vector<char> &str, vector<pair<int,int> > &Qs) {
  int total_yes = 0;
  for (int q=0; q<Qs.size(); q++) {
    if ( palindrome(str, Qs[q].first-1, Qs[q].second-1) ) {
      total_yes++;
    }
  }
  return total_yes;
}

int main() {
  int T, N, Q, aux1, aux2;
  vector<char> str;
  vector<pair<int,int> > v;
  char c;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N;
    cin >> Q;

    str.resize(N);
    for (int j=0; j<N; j++) {
      cin >> c;
      str[j] = c;
    }

    v.resize(Q);
    for (int j=0; j<Q; j++) {
      cin >> aux1 >> aux2;
      v[j] = pair<int,int> (aux1, aux2);
    }
    cout << "Case #" << i+1 << ": " << Hack(str, v) <<endl;
  }
}
