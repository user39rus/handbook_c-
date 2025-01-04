#include <vector>

using namespace std;

template <typename T> class Table {
private:
  std::vector<std::vector<T>> data;

  void MakeRectangle() {
    size_t MaxSize = 0;
    for (const auto &row : data) {
      if (row.size() > MaxSize) {
        MaxSize = row.size();
      }
    }

    for (auto &row : data) {
      row.resize(MaxSize);
    }
  }

public:
  Table(const vector<vector<T>> &d) : data(d) { MakeRectangle(); }

  Table(size_t rows, size_t columns) {
    data.resize(rows);
    for (auto &row : data) {
      row.resize(columns);
    }
  }

  void resize(size_t n, size_t m) {
    data.resize(n);
    for (auto &row : data) {
      row.resize(m);
    }
  }
  pair<size_t, size_t> size() const {
    if (data.empty()) {
      return {0, 0};
    }
    return {data.size(), data[0].size()};
  }

  size_t GetRows() const { return data.size(); }

  size_t GetColumns() const {
    if (data.empty()) {
      return 0;
    }
    return data[0].size();
  }

  const vector<T> &operator[](size_t i) const { return data[i]; }

  vector<T> &operator[](size_t i) { return data[i]; }
};

#include <iostream>

int main() {
  Table<double> t(3, 4);
  t[1][1] = 5;
  t.resize(2, 3);
  cout << t.GetRows() << endl;
  cout << t.GetColumns() << endl;
  cout << t[1][1] << endl;
  cout << t.size().first<< ' ' << t.size().second << endl;
}