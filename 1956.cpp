#include <iostream>
#include <algorithm>
using namespace std;

int table[401][401];

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 987654321;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            table[i][j] = 987654321;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        table[a][b] = c;
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
        ans = min(ans, table[i][i]);
    }
    cout << ((ans == 987654321) ? -1 : ans);
}