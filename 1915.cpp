#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int table[1001][1001];

int main()
{
    int n, m;
    string str;
    cin >> n >> m;
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++)
        {
            table[i][j] = str[j - 1] - 48;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (table[i][j] == 1)
            {
                table[i][j] = min(min(table[i - 1][j], table[i][j - 1]), table[i - 1][j - 1]) + 1;
                ans = max(ans, table[i][j]);
            }
        }
    }
    cout << (ans) * (ans);
}