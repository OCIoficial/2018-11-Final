#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int D = inf.readInt(1, 100, "D");
  inf.readEoln();
  for (int i = 0; i < D; ++i) {
    inf.readLine("[a-z]{1, 100}", "word");
  }
  inf.readLine("[a-z]{1,100000}", "text");
  inf.readEof();
}
