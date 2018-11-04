#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int D = inf.readInt(1, 100, "D");
  inf.readEoln();
  uint length = -1;
  for (int i = 0; i < D; ++i) {
    string word = inf.readLine("[a-z]{1, 100}", "word");
    if (i > 0)
      ensuref(length == word.size(), "Todas las palabras deben tener el mismo largo.");
    length = word.size();
  }
  inf.readLine("[a-z]{1,100000}", "text");
  inf.readEof();
}
