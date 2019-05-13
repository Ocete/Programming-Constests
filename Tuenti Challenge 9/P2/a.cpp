#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
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

// -----------------------------------------------

map<string, int> dict;

int acces (string &str) {
  if (str == "Galactica") {
    return 0;
  } else {
    auto it = dict.find(str);
    if ( it != dict.end() ) {
      return it->second;
    } else {
      int s = dict.size()-1;
      dict[str] = s;
      return s;
    }
  }
}

int readLine(vector<int> &aux) {
  string line;
  vector<string> v;

  getline(cin, line);

  int i_before, i = line.find_first_of(':');
  v.push_back( line.substr(0, i) );
  i_before = i;
  i = line.find_first_of(',', i_before+1);

  while ( i != string::npos ) {
    v.push_back( line.substr(i_before+1, i-i_before-1) );
    i_before = i;
    i = line.find_first_of(',', i_before+1);
  }
  v.push_back( line.substr(i_before+1, line.size()) );

  int val = acces( v[0] );
  aux.clear();
  FOR( i, 1, v.size() ) {
    aux.push_back( acces(v[i]) );
  }

  return val;
}

void launch(vector<vector<int> > &graph, vector<int> &count, int pos, int NE) {
  count[pos] = 0;
  FOR( i, 0, graph[pos].size() ) {
    if ( graph[pos][i] == NE) {
      count[pos]++;
    } else if ( count[ graph[pos][i] ] >= 0 ) {
      count[pos] += count[ graph[pos][i] ];
    } else {
      launch(graph, count, graph[pos][i], NE);
      count[pos] += count[ graph[pos][i] ];
    }
  }
}

int Hack(vector<vector<int> > &graph, int NE) {
  vector<int> count (NE, -1);
  launch(graph, count, 0, NE);
  return count[0];
}


int main() {
  int T, NE, planet;
  cin >> T;
  vector<vector<int> > graph;
  vector<int> aux;
  string trash;

  for (int i=0; i<T; i++) {
    cin >> NE;

    dict.clear();
    dict["Galactica"] = 0;
    dict["New Earth"] = NE;
    graph.clear();
    graph.resize(NE);

    // Read trash
    getline(cin, trash);

    FOR (j, 0, NE) {
      planet = readLine(aux);
      graph[planet] = aux;
    }
    cout << "Case #" << i+1 << ": " << Hack(graph, NE) << endl;
  }
}
