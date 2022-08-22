#include <iostream>
#include <algorithm>
using namespace std;

int table[1001];
int dp[1001];

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (table[i] > table[j])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}