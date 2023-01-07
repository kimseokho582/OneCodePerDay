#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char table[2001][2001];
int cmp[2002][2002] = {
    0,
};

int n, m, k;
int calc(char x)
{
    memset(cmp, 0, sizeof(cmp));
    int num = 0;
    int small = 999999999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) % 2)
            {
                num = table[i][j] == x ? 1 : 0;
            }
            else
            {
                num = table[i][j] != x ? 1 : 0;
            }
            cmp[i + 1][j + 1] = cmp[i][j + 1] + cmp[i + 1][j] - cmp[i][j] + num;
        }
    }

    for (int i = 1; i <= n - k + 1; i++)
    {
        for (int j = 1; j <= m - k + 1; j++)
        {
            small = min(small, cmp[i + k - 1][j + k - 1] - cmp[i + k - 1][j - 1] - cmp[i - 1][j + k - 1] + cmp[i - 1][j - 1]);
        }
    }
    return small;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            table[i][j] = str[j];
        }
    }

    cout << min(calc('B'), calc('W'));
}