#include "logger.h"

int main() {
    Logger a;
    Logger b;
    a = b;
    a = std::move(b);
}