#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct activity {
  int start, end, pos;
  char who;
};

activity readActivity (int i) {
  activity act;
  cin >> act.start;
  cin >> act.end;
  act.pos = i;
  return act;
}

bool compareActivities(activity act1, activity act2) {
  return act1.start < act2.start;
}

bool compareActivitiesByPos(activity act1, activity act2) {
  return act1.pos < act2.pos;
}

string P3(vector<activity> v) {
  sort(v.begin(), v.end(), compareActivities);

  int C = 0, J = 0;

  for (int i=0; i<v.size(); i++) {
    if (C <= v[i].start) {
      C = v[i].end;
      v[i].who = 'C';
    } else if (J <= v[i].start) {
      J = v[i].end;
      v[i].who = 'J';
    } else {
      return "IMPOSSIBLE";
    }
  }

  sort(v.begin(), v.end(), compareActivitiesByPos);
  stringstream ss;
  for (int i=0; i<v.size(); i++)
    ss << v[i].who;

  return ss.str();
}

int main() {
  int T, N;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N;
    vector<activity> v;
    for (int j=0; j<N; j++) {
      v.push_back( readActivity(j) );
    }
    cout << "Case #" << i+1 << ": " << P3(v) << endl;
  }
}
