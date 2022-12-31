#include <iostream>

using namespace std;

long long table[101][11];

int main()
{
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= 9; i++)
    {
        table[1][i] = 1;
    }
    table[1][0] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
                table[i][j] = table[i - 1][j + 1] % 1000000000;
            else if (j == 9)
                table[i][j] = table[i - 1][j - 1] % 1000000000;
            else
                table[i][j] = (table[i - 1][j + 1] + table[i - 1][j - 1]) % 1000000000;
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        ans = (ans + table[n][i]) % 1000000000;
    }
    cout << ans % 1000000000;
}