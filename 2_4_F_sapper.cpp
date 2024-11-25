#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n, m, number_of_bombs;
  cin >> n >> m >> number_of_bombs;
  vector<vector<int>> field(n, vector<int>(m));
  for (int i = 0; i < number_of_bombs; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    field[x][y] = -1000000;
    if ((x - 1) >= 0 && (y - 1) >= 0)
      field[x - 1][y - 1]++;
    if ((x - 1) >= 0)
      field[x - 1][y] += 1;
    if ((x - 1) >= 0 && (y + 1) < m)
      field[x - 1][y + 1]++;
    if ((y - 1) >= 0)
      field[x][y - 1]++;
    if ((y + 1) < m)
      field[x][y + 1]++;
    if ((x + 1) < n && (y - 1) >= 0)
      field[x + 1][y - 1]++;
    if ((x + 1) < n)
      field[x + 1][y]++;
    if ((x + 1) < n && (y + 1) < m)
      field[x + 1][y + 1]++;
  }
  for (int i = 0; i < n; ++i) {
    if (field[i][0] < 0)
      cout << "*";
    else
      cout << field[i][0];

    for (int j = 1; j < m; ++j) {
      cout.width(2);
      if (field[i][j] < 0)
        cout << " *";
      else
        cout << field[i][j];
    }
    cout << "\n";
  }
}