#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> // exit
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int middle(int a, int b) {
  return (a+b)/2;
}

int side(int max, int min) {
  int side = (max-min)/4;
  return side == 0 ? 1 : side;
}

string P2(int U) {
  int limit = 10000;
  int aux;
  string str;
  map<char, int> m;
  char letter;
  set<char> s;

  for (int i=0; i<10000; i++) {
    cin >> aux;
    cin >> str;

    letter = str[0];

    if (s.size() < 10) {
      for (int i=0; i<str.size(); i++)
        s.insert( str[i] );
    }

    if (m.count(letter) == 0) {
      m[letter] = 1;
    } else {
      m[letter]++;
    }
  }

  vector<pair<char,int>> v;
  for (auto it=m.begin(); it!=m.end(); it++) {
    v.push_back(pair<char,int> (it->first, it->second));
    s.erase(it->first);
  }

  sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs )
  {
     return lhs.second > rhs.second;
  });

  string result;
  result.push_back( *s.begin() );
  for (int i=0; i<v.size(); i++) {
    result += v[i].first;
  }

  return result;
}

int main() {
  int T, U;
  cin >> T;
  for (int i=0; i<T; i++) {
  cin >> U;
    cout << "Case #" << i+1 << ": " << P2(U) << endl;
  }
}
