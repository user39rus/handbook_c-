#include <cmath>
#include <chrono>
#include <iostream>
#include <string>
class TimerGuard {
  std::chrono::time_point<std::chrono::high_resolution_clock> start;
  std::string message;
  std::ostream &out;

public:
  TimerGuard(std::string message = "", std::ostream &out = std::cout)
      : start(std::chrono::high_resolution_clock::now()), message(message),
        out(out) {}
  ~TimerGuard() {
        auto end = std::chrono::high_resolution_clock::now();  // конец - вызов деструктора
        std::chrono::duration<double> diff = end - start;
    out << message << " " << diff.count() << "\n";
  }
};
void SomeFunc() {
  long long n = 2;
  {
    TimerGuard guard("FirstLongFunction", std::cout);
    n *= n;
  }
  auto start2 = std::chrono::high_resolution_clock::now();
  n = pow(2, 10);
  std::chrono::duration<double> diff2 =
      std::chrono::high_resolution_clock::now() - start2;
  std::cout << "SecondLongFunction elapsed: " << diff2.count() << "\n";

  auto start3 = std::chrono::high_resolution_clock::now();
  n = pow(2, 20);
  std::chrono::duration<double> diff3 =
      std::chrono::high_resolution_clock::now() - start3;
  std::cout << "ThirdLongFunction elapsed: " << diff3.count() << "\n";
}

int main() {
  SomeFunc();
  return 0;
}