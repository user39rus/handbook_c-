#include <deque>

using namespace std;

template <typename T, typename Container = deque<T>> class Queue {
private:
  Container data;

public:
  Queue() : data() {}

  const T &front() const { return data.front(); }

  T &front() { return data.front(); }

  void pop() { data.pop_front(); }

  void push(const T &n) { data.push_back(n); }

  size_t size() const { return data.size(); }

  bool empty() {
    return data.empty();
  }

  bool operator==(const Queue &other) const {
    return data==other.data;
  }

  bool operator!=(const Queue &other) const { return !(operator==(other)); }
};

#include <iostream>

int main() {
  Queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);

  cout << "Front: " << q.front() << endl; // Ожидается 1
  cout << "Size: " << q.size() << endl;   // Ожидается 3

  q.pop();
  cout << "Front after pop: " << q.front() << endl; // Ожидается 2
  cout << "Size after pop: " << q.size() << endl;   // Ожидается 2

  return 0;
}