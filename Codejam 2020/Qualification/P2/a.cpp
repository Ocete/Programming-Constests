#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int ctoi(char c) {
  return c - '0';
}

string P2(string str) {
  int current_depth = 0, i = 0;
  stringstream ss;

  while (i < str.length()) {
    if (ctoi(str[i]) == current_depth) {
      ss << str[i];
      i++;
    } else if (ctoi(str[i]) > current_depth) {
      ss << '(';
      current_depth++;
    } else {
      ss << ')';
      current_depth--;
    }
  }
  while (current_depth > 0) {
    ss << ')';
    current_depth--;
  }
  return ss.str();
}

int main() {

  int T, N;
  string str;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> str;
    cout << "Case #" << i+1 << ": " << P2(str) << endl;
  }
}
