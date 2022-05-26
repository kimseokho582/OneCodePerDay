#include <iostream>
#include <algorithm>
using namespace std;

int table[10001];
int dp[10001] = {
    0,
};

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> table[i];
    }
    dp[1] = table[1];
    dp[2] = table[1] + table[2];
    int ans = 0;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], table[i] + max(table[i - 1] + dp[i - 3], dp[i - 2]));
    }
    cout << dp[n];
}