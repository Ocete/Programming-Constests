#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void readVector(int N, vector<string> &v) {
  string str;
  v.clear();
  for (int i=0; i<N; i++) {
    cin >> str;
    v.push_back(str);
  }
}

bool match_start(string &str1, string &str2) {
  if (str1.size() > str2.size()) {
    return str1.substr( 0, str2.size()) == str2;
  } else {
    return str2.substr( 0, str1.size()) == str1;
  }
}

bool match_end(string &str1, string &str2) {
  if (str1.size() > str2.size()) {
    return str1.substr( str1.size()-str2.size(), str2.size()) == str2;
  } else {
    return str2.substr( str2.size()-str1.size(), str1.size()) == str1;
  }
}

void cut(string &aux_start, string &middle, string &aux_end, string &str) {
  stringstream ss;
  int ast = str.find("*"), ant_ast;
  aux_start = str.substr(0, ast);
  while (ast != string::npos) {
    ant_ast = ast;
    ast = str.find("*", ast+1);
    if (ast != string::npos)
      ss << str.substr(ant_ast+1, ast-ant_ast-1);
  }
  aux_end = str.substr(ant_ast+1, str.size()-ant_ast-1);
  middle = ss.str();
}

string P1(vector<string> &v) {
  int N = v.size();
  string start = "", end = "";
  string aux_start, aux_end, aux_middle;
  stringstream ss_middle;
  for (int i=0; i<N; i++) {
    cut(aux_start, aux_middle, aux_end, v[i]);

    if ( !match_start(start, aux_start) || !match_end( end, aux_end ) ) {
      return "*";
    }
    if ( aux_start.size() > start.size()) {
      start = aux_start;
    }
    if ( aux_end.size() > end.size()) {
      end = aux_end;
    }
    ss_middle << aux_middle;
  }
  return start + ss_middle.str() + end;
}

int main() {
  int T, N, i;
  vector<string> v;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N;
    readVector(N, v);
    cout << "Case #" << i+1 << ": " << P1(v) << endl;
  }
}
