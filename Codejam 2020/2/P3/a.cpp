#include <iostream>
#include <vector>
#include <algorithm>    // std::min
#include <unordered_map>    // std::min
using namespace std;
void readVector(int N, vector<int> &v) {
  int aux;
  for (int i=0; i<N; i++) {
    cin >> aux;
    v.push_back(aux);
  }
}

void printVector(vector<int> &v) {
  for (int i=0; i<v.size()-1; i++) {
    cout << v[i] << " ";
  }
  cout << v[ v.size()-1 ] << endl;
}

void printVector(vector<bool> &v) {
  for (int i=0; i<v.size()-1; i++) {
    cout << v[i] << " ";
  }
  cout << v[ v.size()-1 ] << endl;
}

pair<int,int> computDir(pair<int,int> &A, pair<int,int> &B) {
  pair<int,int> dir;
  dir.first = B.first - A.first;
  dir.second = B.second - A.second;

  if (dir.first < 0 && dir.second < 0) {
    dir.first = abs(dir.first);
    dir.second = abs(dir.second);
  } else if (dir.first < 0 && dir.second > 0) {
    dir.first = abs(dir.first);
    dir.second = -dir.second;
  } else if ((dir.first == 0 && dir.second < 0) ||
            (dir.first < 0 && dir.second == 0)) {
    dir.first = abs(dir.first);
    dir.second = abs(dir.second);
  }

  return dir;
}

bool inLine(pair<int,int> &P, pair<int,int> &Q, pair<int,int> &d) {
  if (d.first == 0){
    return P.second - Q.second == 0;
  } else if (d.second == 0){
    return P.first - Q.first == 0;
  } else {
    return (P.first- Q.first) * d.second == (P.second- Q.second) * d.first;
  }
}

int P3(vector<pair<int,int> > &points) {
  vector<pair<int,int> > directions;
  int N = points.size();

  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      pair<int,int> dir = computeDir(points[i], points[j]);
      directions.push_back(dir);
    }
  }

  int myMax = 0;
  for (int d=0; i<directions.size(); d++) {
    unordered_map<pair<int,int>, int> m;
    for (int i=0; i<N; i++) {
      m[ points[i] ] = 0;
      for (int j=0; j<N; j++) {
        if (i != j) {
          if ( inLine(points[i], points[j], directions[d]) ) {
            if ( m.count(points[j]) > 0 && m[points[j]] > 0 ) {
              m[points[j]]++;
              m[points[i]] = 0;
            } else {
              m[points[i]]++;
            }
          }
        }
      }
    }

    int count = 0;
    bool b = false;
    for (int it=m.begin; it!=m.end(); it++) {
      if ( (*it).second % 2 == 1 ) {
        b = true;
        (*it).second--;
      }
      count += (*it).second;
    }
    if (b) {
      count++;
    }
    if (count > myMax) {
      myMax = count;
    }
  }
  return myMax;
}

int main() {
  int T, N;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N;

    vector<pair<int,int> > v();
    for (int i=0; i<N; i++) {
      pair<int,int> p;
      cin >> p.first;
      cin >> p.second;
      v.push_back(p);
    }

    cout << "Case #" << i+1 << ": " << P3(v) << endl;

  }
}
