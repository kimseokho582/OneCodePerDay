#include <iostream>
#include <algorithm>
using namespace std;

int table[1001] = {
    0,
};
int dp[1001] = {
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
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] = max(dp[i], max(table[i], dp[i - j] + table[j]));
        }
    }
    cout << dp[n];
}