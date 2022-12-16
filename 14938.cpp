#include <iostream>
#include <algorithm>
using namespace std;

int t[101];
int table[101][101];
int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            table[i][j] = 987654321;
        }
    }
    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        table[a][b] = c;
        table[b][a] = c;
    }
    for (int q = 1; q <= n; q++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                table[i][j] = min(table[i][j], table[i][q] + table[q][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;

        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                tmp += t[j];
            }
            else
            {
                if (table[i][j] <= m)
                {
                    tmp += t[j];
                }
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans;
}