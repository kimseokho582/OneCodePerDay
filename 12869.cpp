#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int table[4];
int dp[61][61][61];

int calc(int a, int b, int c)
{
    if (a < 0)
        return calc(0, b, c);
    if (b < 0)
        return calc(a, 0, c);
    if (c < 0)
        return calc(a, b, 0);

    if (dp[a][b][c] != -1)
        return dp[a][b][c];
    if (a == 0 && b == 0 && c == 0)
        return 0;

    dp[a][b][c] = 999999999;
    dp[a][b][c] = min(dp[a][b][c], calc(a - 9, b - 3, c - 1) + 1);
    dp[a][b][c] = min(dp[a][b][c], calc(a - 9, b - 1, c - 3) + 1);
    dp[a][b][c] = min(dp[a][b][c], calc(a - 3, b - 9, c - 1) + 1);
    dp[a][b][c] = min(dp[a][b][c], calc(a - 3, b - 1, c - 9) + 1);
    dp[a][b][c] = min(dp[a][b][c], calc(a - 1, b - 9, c - 3) + 1);
    dp[a][b][c] = min(dp[a][b][c], calc(a - 1, b - 3, c - 9) + 1);

    return dp[a][b][c];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << calc(table[0], table[1], table[2]);
}