#include <iostream>
#include <algorithm>

using namespace std;

int table[50001] = {0, 1};
int dp[4][50001] = {0, 1};

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        table[i] = table[i - 1] + tmp;
    }
    int m;
    cin >> m;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = i * m; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + table[j] - table[j - m]);
        }
    }
    cout << dp[3][n] << endl;
}