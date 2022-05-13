#include <iostream>
#include <cmath>
using namespace std;
int dp[301];
int table[301];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    dp[0] = table[0];
    dp[1] = table[0] + table[1];
    dp[2] = max(table[0] + table[2], table[1] + table[2]);

    for (int i = 3; i < n; i++)
    {
        dp[i] = max(table[i] + dp[i - 2], table[i] + table[i - 1] + dp[i - 3]);
    }
    cout << dp[n - 1];
}