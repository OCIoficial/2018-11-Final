#include <iostream>
#include <map>
using namespace std;

int M, N;

bool is_final_pos(pair<int, int> pos) {
  if (pos.first < M - 1)
    return false;
  return pos.second == (M%2 == 0 ? 0 : N - 1);
}

int main() {
  cin >> M >> N;
  int E;
  cin >> E;

  map<pair<int,int>, pair<int, int>> m;
  for (int i = 0; i < E; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    m[{a, b}] = {c, d};
  }

  int T;
  cin >> T;
  pair<int, int> pos = {0, 0};
  for (int i = 0; i < T; ++i) {
    int d;
    cin >> d;
    int dir = pos.first % 2 == 0 ? 1 : -1;
    while (d-- > 0) {
      if (is_final_pos(pos)) {
        cout << pos.first << " " << pos.second << "\n";
        return 0;
      }
      if (0 <= pos.second + dir and pos.second + dir < N) {
        pos.second += dir;
      } else {
        pos.first += 1;
        dir = dir == -1 ? 1 : -1;
      }
    }
    if (m.count(pos))
      pos = m[pos];
  }
  cout << pos.first << " " << pos.second << "\n";
  return 0;
}
