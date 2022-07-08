#include <iostream>

using namespace std;

int n;
int table[101][101];
long long ans[101][101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> table[i][j];
        }
    }
    ans[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp = table[i][j];
            if (ans[i][j] == 0)
                continue;
            if (i == n && j == n)
                continue;
            if (i + tmp <= n)
            {
                ans[i + tmp][j] = ans[i + tmp][j] + ans[i][j];
            }

            if (j + tmp <= n)
            {
                ans[i][j + tmp] = ans[i][j + tmp] + ans[i][j];
            }
        }
    }
    cout << ans[n][n];
}