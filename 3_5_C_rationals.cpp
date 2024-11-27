#include <iostream>
#include <numeric>
class Rational {
private:
  int numerator;
  int denominator;

public:
  Rational() : numerator(0), denominator(1){};
  Rational(int n) : numerator(n), denominator(1){};
  Rational(int n, int d) : numerator(n), denominator(d) {
    if (denominator == 0)
      throw std::out_of_range("Zero denominator!");
    Normalize();
  };

  int Numerator() const { return numerator; }
  int Denominator() const { return denominator; }

  Rational &operator+=(const Rational &d) {
    numerator = numerator * d.denominator + denominator * d.numerator;
    denominator = denominator * d.denominator;
    Normalize();
    return *this;
  }

  Rational &operator-=(const Rational &d) {
    numerator = numerator * d.denominator - denominator * d.numerator;
    denominator = denominator * d.denominator;
    Normalize();
    return *this;
  }

  bool operator==(const Rational &d) const {
    return numerator * d.denominator == denominator * d.numerator;
  }

  bool operator!=(const Rational &d) const {
    return numerator * d.denominator != denominator * d.numerator;
  }

  Rational &operator*=(const Rational &d) {
    numerator = numerator * d.numerator;
    denominator = denominator * d.denominator;
    Normalize();
    return *this;
  }
  Rational &operator/=(const Rational &d) {
    int tmp = d.numerator;
    numerator = numerator * d.denominator;
    denominator = denominator * tmp;
    Normalize();
    return *this;
  }
  Rational operator-() const { return Rational(-numerator, denominator); }
  Rational operator+() const { return Rational(numerator, denominator); }

  void Normalize() {
    int gcd = std::gcd(numerator, denominator);
    numerator = numerator / gcd;
    denominator = denominator / gcd;
    if (denominator < 0) {
      denominator *= -1;
      numerator *= -1;
    }
  }
};
Rational operator+(Rational a, Rational d) {
  Rational result =a;
  result += d;
  return result;
}
Rational operator-(Rational a, Rational d) {
  Rational result =a;
  result -= d;
  return result;
}
Rational operator*(Rational a, Rational d) {
  Rational result =a;
  result *= d;
  return result;
}
Rational operator/(Rational a, Rational d) {
  Rational result =a;
  result /= d;
  return result;
}

std::ostream &operator<<(std::ostream &out, const Rational &r) {
  out << r.Numerator() << "/" << r.Denominator();
  return out;
}
using namespace std;
int main() {
  Rational a = {1, 2};
  Rational b = {2, 4};
  // bool c = (a==b);
  cout << b << endl;
  cout << (a != b) << endl;
}