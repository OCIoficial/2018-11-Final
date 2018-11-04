/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */

#include "testlib.h"
#include <vector>

using namespace std;

int main() {
  registerValidation();
  int N = inf.readInt(2, 100000, "N");
  inf.readSpace();
  int D = inf.readInt(1, N - 1, "D");
  inf.readEoln();

  int U = inf.readInt(1, N, "U");
  inf.readSpace();
  int V = inf.readInt(1, N, "V");
  inf.readEoln();

  int X = inf.readInt(1, N, "X");
  inf.readSpace();
  int Y = inf.readInt(1, N, "Y");
  inf.readEoln();

  vector< vector< int > > grid(N, vector< int >(N));

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < N; j++) {
      grid[i][j] = inf.readInt(0, 1, "b_ij");
      inf.readSpace();
    }
    grid[i][j] = inf.readInt(0, 1, "b_ij");
    inf.readEoln();
  }

  inf.readEof();

  ensuref(grid[Y][X] == 1, "Posición inicial debe ser edificio.");
  ensuref(grid[V][U] == 1, "Posición final debe ser edificio.");

  // TODO verificar que haya solución

  return 0;
}
