#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int memory[101];
int cost[101];
int dp[101][10001];

int main()
{
    int sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> memory[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        sum += cost[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j >= cost[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n][i] >= m)
        {
            cout << i;
            break;
        }
    }
}