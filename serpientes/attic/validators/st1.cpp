#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  inf.readInt(2, 1000, "M");
  inf.readSpace();
  inf.readInt(2, 1000, "N");
  inf.readEoln();

  inf.readInt(0, 0, "E");
  inf.readEoln();

  int T = inf.readInt(1, 100, "T");
  inf.readEoln();

  for (int i = 0; i < T; ++i) {
    if (i > 0)
      inf.readSpace();
    inf.readInt(1, 6, "d");
  }
  inf.readEoln();

  inf.readEof();
}
