#include <iostream>
#include <cmath>

using namespace std;

int table[501][501];
int ans = 0;
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int num;
            cin >> num;
            if (i == 1)
            {
                table[i][j] = num;
                continue;
            }
            else if (j == 1)
            {
                table[i][j] = num + table[i - 1][j];
            }
            else if (j == i)
            {
                table[i][j] = num + table[i - 1][j - 1];
            }
            else
            {
                table[i][j] = max(table[i - 1][j], table[i - 1][j - 1]) + num;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, table[n][i]);
    }
    cout << ans;
}