#include <iostream>
#include <vector>
#include <algorithm>    // std::min
using namespace std;

struct graph {
  int C;
  int D;
  vector <int> info; // C-1 size
  vector<pair<int,int>> links; // D size
};

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

int findNextNode(int round, vector<bool> &connected, vector<int> &info){
  int C = info.size();
  int too_much = 1000000;
  int min = too_much, index_min = -1;
  int min_round = too_much, index_min_round = -1;

  for (int i=2; i<C; i++) {
    if (info[i] < 0) {
      if (!connected[i] && -info[i] < round && -info[i] < min_round ) {
        index_min_round = i;
        min_round = -info[i];
      }
    } else {
      if (!connected[i] && info[i] < min) {
        index_min = i;
        min = info[i];
      }
    }
  }
  if (index_min_round != -1)
    return index_min_round;
  else
    return index_min;
}

int findNextLink(int next, vector<bool> &connected, vector<pair<int,int>> &links, vector<int> &info){
  int D = links.size();
  bool reason1, reason2, reason3;

  for (int i=0; i<D; i++) {
    //cout << links[i].first<< " " <<  links[i].second << " " << next << endl;
    reason1 = links[i].first == next || links[i].second == next;
    reason2 = connected[ links[i].first ] || connected[ links[i].second ];
    reason3 = (info[next] > 0) || (info[links[i].first] != info[links[i].second]); // don't connect
      // two nodes that are reached at the same time
    if (reason1 && reason2 && reason3)
      return i;
  }
  cout << "ERROR: No link found" << endl;
  return -1;
}

int connectedTo(int next, int l, vector<pair<int,int>> &links){
  if (links[l].first == next)
    return links[l].second;
  return links[l].first;
}

int P2(graph &g) {
  int round = 2;
  int next;
  int myLink;
  int nextConnectedTo;
  int actualTime = 1;
  int computedDelay;

  vector<int> latencies(g.D, 100000);
  vector<bool> connected(g.C + 1, false);
  vector<int> timeToThisNode(g.C + 1, 0);
  timeToThisNode[1] = 0; // source has the update
  connected[0] = true; // we won't use this guy
  connected[1] = true;

  for (int round=2; round<=g.C; round++) {
    next = findNextNode(round, connected, g.info);
    myLink = findNextLink(next, connected, g.links, g.info);
    nextConnectedTo = connectedTo(next, myLink, g.links);

    //cout << next << " - " << myLink << endl;
    //printVector(connected);
    if (g.info[next] < 0) {
      actualTime = max(actualTime, timeToThisNode[nextConnectedTo]);
      if (round - 1 == -g.info[next])
        actualTime++;
    } else {
      actualTime = g.info[next];
    }
    computedDelay = actualTime - timeToThisNode[nextConnectedTo];

    timeToThisNode[next] = actualTime;
    latencies[myLink] = computedDelay;
    connected[next] = true;
  }
  printVector(latencies);
}

int main() {
  int T, C, D;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> C;
    cin >> D;

    graph g;
    g.C = C;
    g.D = D;

    vector<int> v(2, 1000000);
    readVector(C-1, v);
    g.info = v;
    g.links = vector<pair<int,int> >();

    for (int i=0; i<D; i++) {
      pair<int,int> p;
      cin >> p.first;
      cin >> p.second;
      g.links.push_back(p);
    }

    cout << "Case #" << i+1 << ": ";
    P2(g);
  }
}
