#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N, d, U, V, X, Y;
vector<vector<int>> city;

template<typename Fun>
void neighbors(int a, int b, Fun f) {
  for (int i = a - d; i <= a + d; ++i) {
    for (int j = b - d; j <= b + d; ++j) {
      if (i > 0 and j > 0 and i <= N and j <= N and city[i][j]) {
        f(i, j);
      }
    }
  }
}

int bfs() {
  vector<vector<int>> dist(N + 1, vector<int>(N + 1, -1));
  queue<pair<int, int>> q;
  q.emplace(U, V);
  dist[U][V] = 0;
  while (!q.empty()) {
    int a, b;
    tie(a, b) = q.front();
    q.pop();
    if (a == X and b == Y)
      return dist[a][b];
    neighbors(a, b, [&](int va, int vb) {
        if (dist[va][vb] == -1) {
          dist[va][vb] = dist[a][b] + 1;
          q.emplace(va, vb);
        }
    });
  }
  return -1;
}

int main() {
  cin >> N >> d;
  cin >> U >> V;
  cin >> X >> Y;

  city.resize(N + 1, vector<int>(N + 1));
  for (int j = 1; j <= N; ++j) {
    for (int i = 1; i <= N; ++i) {
      cin >> city[i][j];
    }
  }
  cout << bfs() << "\n";
}
