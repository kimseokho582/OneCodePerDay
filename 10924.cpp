#include <iostream>

using namespace std;

int table[2001];
int dp[2001][2001];

int main()
{

ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> table[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
        if (table[i] == table[i - 1])
        {
            dp[i - 1][i] = 1;
        }
    }

    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            int k = i + j;
            if (table[j] == table[k] && dp[j + 1][k - 1] == 1)
            {
                dp[j][k] = 1;
            }
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << "\n";
    }
}