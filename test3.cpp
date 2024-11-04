#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<string> parts(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> parts[i];
  }

  vector<int> parent(N + 1, -1);
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    parent[a] = b;
  }

  int root = 1;
  while (parent[root] != -1) {
    root = parent[root];
  }

  string result;

  function<void(int)> dfs = [&](int node) {
    if (node == -1)
      return;
    result += parts[node];
    for (int i = 1; i <= N; ++i) {
      if (parent[i] == node) {
        dfs(i);
      }
    }
  };

  dfs(root);
  cout << result << endl;

  return 0;
}
