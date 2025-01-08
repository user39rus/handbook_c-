#include "logger.h"
#include <list>
int main() {
    int n;
    std::cin>>n;
    std::list<Logger> loggers;
    for (int i=0; i<n; ++i) {
        loggers.emplace_back();
    }
}