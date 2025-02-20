#include "testlib.h"
#include <set>
using namespace std;

pair<int, int> final_pos(int M, int N) {
  return M % 2 == 0 ? make_pair(M-1, 0) : make_pair(M-1, N-1);
}

int main() {
  registerValidation();
  int M = inf.readInt(2, 1000, "M");
  inf.readSpace();
  int N = inf.readInt(2, 1000, "N");
  inf.readEoln();

  int E = inf.readInt(1, 100, "E");
  inf.readEoln();
  set<pair<int, int>> start;
  set<pair<int, int>> end;
  auto fp = final_pos(M, N);
  for (int i = 0; i < E; ++i) {
    int a = inf.readInt(0, M - 1, "a");
    inf.readSpace();
    int b = inf.readInt(0, N - 1, "b");
    inf.readSpace();
    int c = inf.readInt(0, M - 1, "c");
    inf.readSpace();
    int d = inf.readInt(0, N - 1, "d");
    inf.readEoln();
    ensuref(a != fp.first or b != fp.second, "Un objeto no puede empezar en la casilla final");
    ensuref(a != 0 or b != 0, "Un objeto no puede empezar en la casilla inicial");
    ensuref(a != c or b != d, "Un objeto no puede empezar donde termina");
    ensuref(start.count({a, b}) == 0, "Dos objetos no pueden empezar en la misma posición");
    ensuref(end.count({a, b}) == 0, "Un objeto no pueden empezar donde termina otro");
    start.insert({a, b});
    end.insert({c, d});
  }

  int T = inf.readInt(1, 10000, "T");
  inf.readEoln();
  for (int i = 0; i < T; ++i) {
    if (i > 0)
      inf.readSpace();
    inf.readInt(1, 6, "d");
  }
  inf.readEoln();

  inf.readEof();
}
