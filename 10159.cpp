#include <iostream>
#include <algorithm>
int table[101][101] = {
    0,
};

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        table[x][y] = 1;
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!table[i][j] && !table[j][i])
                ans++;
        }
        cout << ans - 1 << "\n";
    }
}
