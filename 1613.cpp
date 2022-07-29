#include <iostream>
#include <algorithm>
using namespace std;

int table[401][401];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        table[a][b] = 1;
    }

    for (int q = 1; q <= n; q++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (table[i][q] && table[q][j])
                {
                    table[i][j] = 1;
                }
            }
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        if (table[a][b] == 1)
        {
            cout << -1 << "\n";
        }
        else if (table[b][a] == 1)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}