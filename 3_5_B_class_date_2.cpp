class Date {
private:
  int totaldays;

  bool isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  }
  int daysInYear(int year) const { return isLeapYear(year) ? 366 : 365; }
  int daysInMonth(int month, int year) const {
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
  int DateToDay(int day, int month, int year) const {
    int days = 0;
    for (int i = 1970; i < year; ++i) {
      days += daysInYear(i);
    }
    for (int i = 1; i < month; ++i) {
      days += daysInMonth(i, year);
    }
    days += day - 1;
    return days;
  }
  void DayToDate(int days, int *day, int *month, int *year) const {
    *day += days;
    while (*day > daysInMonth(*month, *year)) {
      *day -= daysInMonth(*month, *year);
      ++(*month);
      if (*month > 12) {
        *month = 1;
        ++(*year);
      }
    }
    while (*day < 1) {
      --(*month);
      if (*month < 1) {
        *month = 12;
        --(*year);
      }
      *day += daysInMonth(*month, *year);
    }
  }

public:
  Date() : totaldays(0){};
  Date(int d, int m, int y) { totaldays = DateToDay(d, m, y); };

  int GetDay() const { 
    int day=1, month=1, year=1970;
    DayToDate(totaldays, &day,&month, &year);
    return day; }
   int GetMonth() const{ 
    int day=1, month=1, year=1970;
    DayToDate(totaldays, &day,&month, &year);
    return month; }
  int GetYear() const { 
    int day=1, month=1, year=1970;
    DayToDate(totaldays, &day,&month, &year);
    return year; }

  Date &operator+=(int d) {
    totaldays += d;

    return *this;
  }

  Date operator+(int d) {
    totaldays += d;
    return *this;
  }
  Date operator-(int d) {
    totaldays -= d;
    return *this;
  }

  int operator-(const Date &d) const {
    return this->totaldays - d.totaldays;
  }
};
#include <iostream>
std::ostream &operator<<(std::ostream &out,const Date& d) {
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
  Date date2 = date + 365;
  cout << "Date: " << date2 << endl;

  return 0;
}