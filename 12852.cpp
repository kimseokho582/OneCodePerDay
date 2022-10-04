#include <iostream>

using namespace std;

int dp[1000001];
int table[1000001];

int calc(int x)
{
    dp[1] = 0;
    for (int i = 2; i <= x; i++)
    {
        dp[i] = dp[i - 1] + 1;
        table[i] = i - 1;
        if (!(i % 3))
        {
            if (dp[i] > dp[i / 3] + 1)
            {
                dp[i] = dp[i / 3] + 1;
                table[i] = i / 3;
            }
        }
        if (!(i % 2))
        {
            if (dp[i] > dp[i / 2] + 1)
            {
                dp[i] = dp[i / 2] + 1;
                table[i] = i / 2;
            }
        }
    }
    return dp[x];
}

int main()
{
    int n;
    cin >> n;
    cout << calc(n) << "\n";
    while (n)
    {
        cout << n << " ";
        n = table[n];
    }
}