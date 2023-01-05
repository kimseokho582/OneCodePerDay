#include <iostream>
#include <algorithm>
using namespace std;

int table[501];
int sum[501] = {
    0,
};
int dp[501][501];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> table[i];
            sum[i] = sum[i - 1] + table[i];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n - i; j++)
            {
                dp[j][i + j] = 1000000000;
                for (int k = j; k < i + j; k++)
                {
                    dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
                }
            }
        }
        cout << dp[1][n] << endl;
    }
}
