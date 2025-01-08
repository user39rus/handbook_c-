#include "logger.h"

int main() {
  Logger *a = new Logger();
  Logger *b = new Logger();
  Logger *c = new Logger();
  delete b;
  delete c;
  delete a;
}