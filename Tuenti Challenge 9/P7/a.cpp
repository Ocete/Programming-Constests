#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;
#define FOR(i,A,B) for(int i=A; i<B; i++)

template <class T>
void pVector(vector<T> &v) {
  FOR(i,0,v.size()) {
    cout << v[i] << " ";
  }
  cout << endl;
}

template <class T>
void pMatrix(vector<vector<T> > &m) {
  FOR(i,0,m.size()) {
    cout << i << " -> ";
    pVector(m[i]);
  }
}

template <class A, class B>
void pMap(map<A,B> &m) {
  auto it = m.begin();
  for ( ; it != m.end(); it++) {
    cout << it->first << " -> " < it->second << endl;
  }
}

template <class A, class B>
void pPair(pair<A,B> &p) {
  cout << "(" << p.first << " , " << p.second  << ")";
}

// -----------------------------------------------

typedef char byte;

void pHash(vector<char> &v) {
  cout << "[";
  FOR (i, 0, v.size()) {
    cout << (int) v[i] << " ";
  }
  cout << "]" << endl;
}

void myPrint(string &mess) {
  int j=0;
  FOR(i, 0, mess.size()) {
    if (mess[i] != ' ') {
      cout << mess[i] << " ";
    } else {
      cout << '~' << " ";
    }
    if ( (j+1) % 16 == 0 ) {
      cout << endl;
    }
    j++;
  }
  cout << endl;
}

void notSoComplexHash(string &w1, string &w2, vector<char> &hash, int j) {
    for (int i = 0; i < w1.length(); i++) {
      if (w1[i] != '\r' && w1[i] != '\n') {
        hash[j % 16] = (hash[j % 16] + w1[i]);
        j++;
      }
    }
    for (int i = 0; i < w2.length(); i++) {
      if (w2[i] != '\r' && w2[i] != '\n') {
        hash[j % 16] = (hash[j % 16] + w2[i]);
        j++;
      }
    }
}

vector<char> notSoComplexHash(string &inputText, int &j) {
    vector<byte> hash = vector<byte>(16, 0x00);
    j=0;
    for (int i = 0; i < inputText.length(); i++) {
      if (inputText[i] != '\r' && inputText[i] != '\n') {
        hash[j % 16] = (hash[j % 16] + inputText[i]);
        j++;
      }
    }
    return hash;
}

vector<char> notSoComplexHash(string &inputText) {
    vector<byte> hash = vector<byte>(16, 0x00);
    int j=0;
    for (int i = 0; i < inputText.length(); i++) {
      if (inputText[i] != '\r' && inputText[i] != '\n') {
        hash[j % 16] = (hash[j % 16] + inputText[i]);
        j++;
      }
    }
    return hash;
}

bool HayMultiplo(int inf, int sup) {
  // if (sup - inf > 256) {
  //   return true;
  // }
  int mult = 0, base = 256;
  bool hay = false;
  while (sup < 0) {
    sup += base;
    inf += base;
  }
  while (mult <= sup) {
    if ( mult >= inf && mult <= sup) {
      hay = true;
    }
    mult += base;
  }
  return hay;
}

bool isPossible(vector<char> &A, vector<char> &B, vector<int> &C) {
  bool poss = true;
  int i=0;
  int inf, sup;

  vector<int> M = C;
  FOR(i, 0, M.size()) {
    M[i] = A[i] - (B[i] - C[i]*'0');
  }

  while (poss && i<A.size()) {
    if (C[i] == 0) {
      poss = A[i] == B[i];
    } else {
      // inf = '0'*C[i] + M[i];
      // sup = 'z'*C[i] + M[i];
      // inf = (int)A[i]-(int)B[i]+2*C[i]*'0';
      // sup = (int)A[i]-(int)B[i]+C[i]*('z'+'0');

      inf = (int)B[i] - (int)A[i];
      sup = (int)B[i] + C[i]*74 - (int)A[i];

      poss = HayMultiplo(inf, sup);
      int diff = (A[i] - B[i] + 256) % 256;
      poss = poss && (diff <= C[i]*74);
      // cout << "calculito: " << (int)A[i] << " " << (int)B[i] << " " << C[i] << endl;
      // cout << "multiplo: " << i << " " << inf << " " << sup << endl;
      // cout << "diferencias: " << i << " " << diff << " " << C[i] << " " << C[i]*74  << " " << poss << endl;
    }
    i++;
  }
  return poss;
}

int Ncar(vector<char> &A, vector<char> &B, vector<int> &C,
  vector<char> &first_part_hash, string &last_part, int j_hash, int guion, string &first_part) {
    int j=guion-1, n_car = 0;
    bool stop = false, first_pass = true;
    vector<char> hash = first_part_hash;
    string mess = "";

    while ( !stop ) {
      if (!first_pass) {
        n_car++;
        C[j]++;
        mess.append("0");
      }
      j = (j+1)%C.size();

      // cout << "\t\t\tTamaño: " << n_car << endl;
      // if (n_car == 47) {
      //   stringstream ss;
      //   ss << first_part << mess << last_part;
      //   string auxx = ss.str();
      //   myPrint(auxx);
      // }
      //

      hash = first_part_hash;
      notSoComplexHash(mess, last_part, hash, j_hash);
      // cout << "Calling pos " << n_car << endl;
      stop = isPossible(A, hash, C);
      first_pass = false;
    }
    B = hash;
    return n_car;
  }

void ComputeMess(string &mess, vector<char> &A, vector<char> &B,
                  vector<int> &C, int starting_j) {
  vector<int> diff (C.size(), 0);
  int aux, j;

  FOR(i, 0, C.size()) {
    diff[i] = (A[i] - B[i] + 256) % 256;
  }

  int M = mess.size(), tam_fila = C.size(), n_filas = M/tam_fila;
  starting_j = starting_j%tam_fila;

  vector<char> aux3;
  vector<vector<char> > mat_mess (tam_fila, aux3);

  int i = starting_j;
  FOR(k, 0, tam_fila) {
    j = (tam_fila)*(n_filas) + k ;
    while (j >= M) {
      // cout << "holi " << j << endl;
      j -= tam_fila;
    }
    while ( diff[i] > 0 ) {
      mess[j] = '0' + min(74, diff[i]);
      diff[i] -= min(74, diff[i]);
      j -= tam_fila;
      // cout << "Testing: " << diff[i] << " " << mess[j] << " " << (char) ('0'+min(74,diff[j%tam_fila])) << endl;
      if (j < 0 && diff[i] > 0){
        cout << "Error en ComputeMess " << j << " " << i << endl;
        mess[j+tam_fila] = '#';
        break;
      }
    }
    i = (i+1)%tam_fila;
  }
}

void Hack(string &original, string &altered) {
  // cout << original << endl;
  // cout << "Altered:" << altered << endl;

  vector<char> A, B;
  A = notSoComplexHash(original);
  vector<char> M (A.size(), 0x00);
  vector<int> C (M.size(), 0);

  int pos = altered.find_first_of('-'), j_hash=0;;
  string first_part = altered.substr(0, pos+3);
  string last_part = altered.substr(pos+3, string::npos);
  vector<char> first_part_hash = notSoComplexHash(first_part, j_hash);

  int n_car = Ncar(A, B, C, first_part_hash, last_part, j_hash, pos+3, first_part);
  string mess (n_car, '0');
  // cout << "first_part: " << altered.substr(0, pos+3) <<endl;
  ComputeMess(mess, A, B, C, pos+3);

  // cout << "test" << endl;
  // vector<char> h2;
  // stringstream ss;
  // ss << first_part << mess << last_part;
  // string auxx = ss.str();
  // h2 = notSoComplexHash(auxx);
  // pHash(A);
  // pHash(h2);
  // myPrint(auxx);
  // auto diff = C;
  // FOR(i, 0, diff.size()) {
  //   diff[i] = (A[i]-B[i]+256)%256;
  // }
  // pVector(C);
  // pVector(diff);

  cout << mess << endl;
}

int main() {
  int T, M;
  string original, altered, aux, trash;

  cin >> T;
  for (int i=0; i<T; i++) {
    stringstream ss, ss2;

    cin >> M;
    getline(cin, trash);
    FOR (j, 0, M) {
      getline(cin, aux);
      ss << aux;
    }
    original = ss.str();

    cin >> M;
    getline(cin, trash);
    FOR (j, 0, M) {
      getline(cin, aux);
      ss2 << aux;
    }
    altered = ss2.str();

    cout << "Case #" << i+1 << ": " ;
    Hack(original, altered);
  }
}
