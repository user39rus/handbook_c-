#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<vector<vector<int>>> vec(7, vector<vector<int>>(7, vector<int>(7, 1)));

    int a, b, c;
    char ch;
    while (cin >> ch >> a >> b >> c)
    {
        int sum = 0;
        for (int i = 0; i < 7; ++i)
        {
            for (int j = 0; j < 7; ++j)
            {
                for (int k = 0; k < 7; ++k)
                {
                    if (ch == 't')
                        if (i != a && j != b && k != c)
                            vec[i][j][k] = 0;
                    if (ch == 'f')
                        if (i == a || j == b || k == c)
                            vec[i][j][k] = 0;
                }
            }
        }
        for (int i = 0; i < 7; ++i)
        {
            for (int j = 0; j < 7; ++j)
            {
                for (int k = 0; k < 7; ++k)
                {
                    sum += vec[i][j][k];
                }
            }
        }

        // Выводим сумму
        cout << "число элементов: " << sum << endl;
    }
    return 0;
}