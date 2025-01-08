#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
template <typename T> 
class Polynomial {
public:
  using Container = typename std::vector<T>;
  using ConstIterator = typename Container::const_iterator;

private:
  Container coefficients;
  inline static const T valueTypeZero{0};

  void Normalize() {
    while (!coefficients.empty() && coefficients.back() == valueTypeZero) {
      coefficients.pop_back();
    }
  }
  Container &GetCoefficients() { return coefficients; }

public:
  Polynomial(const Container &coeffs) : coefficients{coeffs} { Normalize(); };

  Polynomial(const T &value = {}) {
    if (value != valueTypeZero) {
      coefficients.push_back(value);
    }
  }

  template <typename Iter>
  Polynomial(Iter begin, Iter end) : coefficients{begin, end} {
    Normalize();
  }

  const Container &GetCoefficients() const { return coefficients; }

  friend bool operator==(const Polynomial<T> &lhs, const Polynomial<T> &rhs) {
    return lhs.GetCoefficients() == rhs.GetCoefficients();
  }

  friend bool operator!=(const Polynomial<T> &lhs, const Polynomial<T> &rhs) {
    return !(lhs == rhs);
  }

  Polynomial<T> &operator+=(const Polynomial<T> &other) {
    if (other.Degree() > Degree()) {
      GetCoefficients().resize(other.Degree() + 1);
    }
    for (int i = 0; i <= Degree() && i <= other.Degree(); ++i) {
      GetCoefficients()[i] += other.GetCoefficients()[i];
    }
    Normalize();
    return *this;
  }
  Polynomial<T> &operator-=(const Polynomial<T> &other) {
    if (other.Degree() > Degree()) {
      GetCoefficients().resize(other.Degree() + 1);
    }
    for (int i = 0; i <= Degree() && i <= other.Degree(); ++i) {
      GetCoefficients()[i] -= other.GetCoefficients()[i];
    }
    Normalize();
    return *this;
  }
  Polynomial<T> &operator*=(const Polynomial<T> &other) {
    if (Degree() == -1 || other.Degree() == -1) {
      GetCoefficients().resize(0);
      return *this;
    }
    vector<T> tmp(Degree() + other.Degree() + 1);
    for (int i = 0; i <= Degree(); ++i) {
      for (int j = 0; j <= other.Degree(); ++j) {
        tmp[i + j] += GetCoefficients()[i] * other.GetCoefficients()[j];
      }
    }
    GetCoefficients() = std::move(tmp);
    Normalize();
    return *this;
  }

  friend Polynomial<T> operator+(Polynomial<T> lhs, const Polynomial<T> &rhs) {
    return lhs += rhs;
  }
  friend Polynomial<T> operator-(Polynomial<T> lhs, const Polynomial<T> &rhs) {
    return lhs -= rhs;
  }
  friend Polynomial<T> operator*(Polynomial<T> lhs, const Polynomial<T> &rhs) {
    return lhs *= rhs;
  }

  int Degree() const { return static_cast<int>(GetCoefficients().size()) - 1; }

  const T &operator[](size_t power) const {
    if (static_cast<int>(power) > Degree()) {
      return valueTypeZero;
    }
    return GetCoefficients()[power];
  }

  T operator()(const T &given_value) const {
    T result = valueTypeZero;
    for (auto i = Degree(); i >= 0; --i) {
      result *= given_value;
      result += GetCoefficients()[i];
    }
    return result;
  }

  ConstIterator begin() const { return GetCoefficients().begin(); }
  ConstIterator end() const { return GetCoefficients().end(); }
};

template <typename T>
ostream &operator<<(ostream &out, const Polynomial<T> &polynomial) {
  for (auto i = polynomial.Degree(); i >= 0; --i) {
    out << polynomial[i];
    if (i != 0) {
      out << " ";
    }
  }
  return out;
};

int main() {
  // Создание многочлена 2x^2 + 3x + 4
  std::vector<int> coeffs1 = {4, 3, 2}; // 4 + 3x + 2x^2
  Polynomial<int> poly1(coeffs1);

  // Создание многочлена x^2 + 2x + 1
  std::vector<int> coeffs2 = {1, 2, 1}; // 1 + 2x + 1x^2
  Polynomial<int> poly2(coeffs2);

  // Сложение многочленов
  Polynomial<int> sum = poly1 + poly2;
  std::cout << "Sum: " << sum << std::endl; // Ожидается: 5 + 5x + 3x^2

  // Вычитание многочленов
  Polynomial<int> difference = poly1 - poly2;
  std::cout << "Difference: " << difference
            << std::endl; // Ожидается: 3 + x + 1x^2

  // Умножение многочленов
  Polynomial<int> product = poly1 * poly2;
  std::cout << "Product: " << product
            << std::endl; // Ожидается: 4 + 11x + 10x^2 + 2x^3

  // Вычисление значения многочлена в точке
  int value = 2; // Подставим x = 2
  std::cout << "poly1(2): " << poly1(value)
            << std::endl; // Ожидается: 4 + 3*2 + 2*2^2 = 4 + 6 + 8 = 18
  std::cout << "poly2(2): " << poly2(value)
            << std::endl; // Ожидается: 1 + 2*2 + 1*2^2 = 1 + 4 + 4 = 9

  return 0;
}