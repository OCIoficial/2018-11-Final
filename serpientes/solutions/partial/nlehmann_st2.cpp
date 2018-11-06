#include <iostream>
#include <vector>
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

  vector<int> snakesA(E);
  vector<int> snakesB(E);
  vector<int> snakesC(E);
  vector<int> snakesD(E);
  for (int i = 0; i < E; ++i)
    cin >> snakesA[i] >> snakesB[i] >> snakesC[i] >> snakesD[i];

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
    for (int i = 0; i < E; ++i) {
      if (pos.first == snakesA[i] and pos.second == snakesB[i])
        pos = {snakesC[i], snakesD[i]};
    }
  }
  cout << pos.first << " " << pos.second << "\n";
  return 0;
}
