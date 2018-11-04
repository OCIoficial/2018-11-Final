#include <iostream>
using namespace std;

int main() {
  int N, M, a, b;
  cin >> N >> M >> a >> b;

  cout << ((N - 1)/a + 1)*((M - 1)/b + 1) << "\n";

  return 0;
}
