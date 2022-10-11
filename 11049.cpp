#include <iostream>

using namespace std;

int table[501][2];
int dp[501][501];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> table[i][0] >> table[i][1];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j + i <= n; j++)
        {
            dp[j][i + j] = 987654321;
            for (int k = j; k < i + j; k++)
            {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + table[j][0] * table[k][1] * table[i + j][1]);
            }
        }
    }
    cout << dp[1][n];
}