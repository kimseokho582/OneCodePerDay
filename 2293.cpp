#include <iostream>

using namespace std;
int dp[100002] = {
    0,
};
int table[102];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> table[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = table[i]; j <= k; j++)
        {
            dp[j] = dp[j] + dp[j - table[i]];
        }
    }
    cout << dp[k];
}