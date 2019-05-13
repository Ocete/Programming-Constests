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

struct node{
  bool used;
  vector<int> v;
};

int letterToPos(char c) {
  return c-'a';
}

char posToLetter(int i) {
  return 'a'+i;
}


void deduce(vector<node> &graph, string &w1, string &w2) {
  int k=0, range = min(w1.size(), w2.size()), i, j;
  while (k < range) {
    if ( w1[k] != w2[k] ) {
      i = letterToPos(w1[k]);
      j = letterToPos(w2[k]);
      auto it = find(graph[i].v.begin(), graph[i].v.end(), j);
      if (it == graph[i].v.end()) {
        graph[i].v.push_back(j);
      }
      return;
    }
    k++;
  }
  return;
}

map<int, pair<int,string> > mem;

void findPath(vector<node> &graph, string &sol, int &length, const int i, bool ambiguous) {
  if (graph[i].v.size() == 0) {
    sol = posToLetter(i);
    length = 0;
  } else {

    int max_length = -1, l;
    sol = "";
    string current_sol = "";

    FOR(j, 0, graph[i].v.size()) {
      if (graph[ graph[i].v[j] ].used) {
        auto it = mem.find(graph[i].v[j]);
        if (it != mem.end()) {
          l = it->second.first;
          current_sol = it->second.second;
        } else {
          findPath(graph, current_sol, l, graph[i].v[j], ambiguous);
        }

        if (l == max_length) {
          ambiguous = true;
        } else if ( l > max_length ) {
          ambiguous = false;
          max_length = l;
          stringstream ss;
          ss << posToLetter(i) << " " << current_sol;
          sol = ss.str();

        }
      }
    }
    length = max_length+1;
  }
  mem[i] = pair<int,string> (length, sol);
}

bool findPath(vector<node> &graph, string &sol, int length) {
  bool found = false, ambiguous = false;
  int l;
  string str;
  FOR(i, 0, graph.size()) {
    if ( graph[i].used ) {
      findPath(graph, str, l, i, ambiguous);
      if ( l == length ) {
        if (found || ambiguous)
          return false;
        sol = str;
        found = true;
      }
    }
  }
  return found;
}

void Hack(vector<string> &words) {
  node n;
  n.used = false;
  vector<node> graph ('z'-'a'+1, n);
  int path_length = 0;

  FOR (i, 0, words.size()) {
    FOR (j, 0, words[i].size()) {
      if ( !graph[ letterToPos(words[i][j]) ].used ) {
        graph[ letterToPos(words[i][j]) ].used = true;
        path_length++;
      }
    }
  }
  path_length--;

  if (words.size() < path_length+1) {
    cout << "AMBIGUOUS" << endl;
    return;
  }

  int i=0;
  FOR(i, 0, words.size()-1) {
    deduce(graph, words[i], words[i+1]);
  }

  /*cout << endl << "Grafo: " << endl;
  FOR (i, 0, graph.size()) {
    if (graph[i].used) {
      cout << i << " -> ";
      pVector(graph[i].v);
    }
  }*/

  string sol;
  bool found = findPath(graph, sol, path_length);

  /*cout << endl << "Mem: " << endl;
  for(auto it=mem.begin(); it!=mem.end(); it++) {
    if (graph[it->first].used)
      cout << it->first << " -> (" << it->second.first << "," << it->second.second << ")" <<endl;
  }*/

  if (!found) {
    sol = "AMBIGUOUS";
  }
  cout << sol << endl;

}

int main() {
  int T, N;
  string aux;
  vector<string> words;

  cin >> T;
  for (int i=0; i<T; i++) {
    mem.clear();
    cin >> N;
    words.resize(N);
    FOR (j, 0, N) {
      cin >> aux;
      words[j] = aux;
    }
    cout << "Case #" << i+1 << ": " ;
    Hack(words);
  }
}
