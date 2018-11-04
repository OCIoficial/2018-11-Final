#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  inf.readInt(1, 10000, "M");
  inf.readSpace();
  inf.readInt(1, 10000, "N");
  inf.readEoln();

  inf.readInt(1, 100, "a");
  inf.readSpace();
  inf.readInt(1, 100, "b");
  inf.readEoln();

  inf.readEof();
}
