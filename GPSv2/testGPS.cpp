#include "gps.h"
#include <cstdio>

int main() {
  try {
    run();

  } catch (exception& e) {
    cerr << "Unhandled Exception: " << e.what() << endl;
  }
}
