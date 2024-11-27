class Date {
private:
  int day;
  int month;
  int year;

public:
  Date() : day(1), month(1), year(1970){};
  Date(int d, int m, int y) : day(d), month(m), year(y) { Normalize(); };

  int GetDay() const { return day; }
  int GetMonth() const { return month; }
  int GetYear() const { return year; }

  bool isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  }
  int daysInYear(int year) const { return isLeapYear(year) ? 366 : 365; }
  int daysInMonth(int month) const {
    switch (month) {
    case 1:
      return 31;
    case 2:
      return isLeapYear(year) ? 29 : 28;
    case 3:
      return 31;
    case 4:
      return 30;
    case 5:
      return 31;
    case 6:
      return 30;
    case 7:
      return 31;
    case 8:
      return 31;
    case 9:
      return 30;
    case 10:
      return 31;
    case 11:
      return 30;
    case 12:
      return 31;
    default:
      return 0;
    }
  }
  void Normalize() {
    while (day > daysInMonth(month)) {
      day -= daysInMonth(month);
      ++month;
      if (month > 12) {
        month = 1;
        ++year;
      }
    }
    while (day < 1) {
      --month;
      if (month < 1) {
        month = 12;
        --year;
      }
      day += daysInMonth(month);
    }
  }
  int DateToDay() const {
    int days = 0;
    for (int i = 1970; i < year; ++i) {
      days += daysInYear(i);
    }
    for (int i = 1; i < month; ++i) {
      days += daysInMonth(i);
    }
    days += day - 1;
    return days;
  }
  Date &operator+=(int d) {
    day += d;
    Normalize();
    return *this;
  }

  Date operator+(int d) {
    day += d;
    Normalize();
    return *this;
  }
  Date operator-(int d) {
    day -= d;
    Normalize();
    return *this;
  }

  int operator-(const Date &d) const {
    return this->DateToDay() - d.DateToDay();
  }
};
#include <iostream>
std::ostream &operator<<(std::ostream &out, const Date &d) {
  out << d.GetDay() << "." << d.GetMonth() << "." << d.GetYear();
  return out;
}
std::istream &operator>>(std::istream &in, Date &data) {
  int d, m, y;
  char dummy;
  in >> d >> dummy;
  in >> m >> dummy;
  in >> y >> dummy;

  data = Date(d, m, y);
  return in;
}

using namespace std;
int main() {
  Date date(1, 2, 1970);
  Date date2 = date - 32;
  cout << "Date: " << date2 << endl;

  return 0;
}