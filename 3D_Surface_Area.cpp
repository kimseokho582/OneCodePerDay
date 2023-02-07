#include <iostream>

using namespace std;

int table[101][101];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
        }
    }

    int ans = n * m * 2;

    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
            {
                tmp += table[i][j];
            }
            else
            {
                if (table[i][j] - table[i - 1][j] > 0)
                {
                    tmp += (table[i][j] - table[i - 1][j]);
                }
            }

            if (j == 0)
            {
                tmp += table[i][j];
            }
            else
            {
                if (table[i][j] - table[i][j - 1] > 0)
                {
                    tmp += (table[i][j] - table[i][j - 1]);
                }
            }
        }
    }
    ans += tmp * 2;
    cout << ans;
}