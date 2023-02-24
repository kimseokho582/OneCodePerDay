#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 99999
int table[51][51] = {
    0,
};
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (str[j] == 'Y')
                {
                    table[i][j] = 1;
                }
                else
                {
                    table[i][j] = MAX;
                }
            }
        }
    }

    for (int q = 0; q < n; q++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                table[i][j] = min(table[i][j], table[i][q] + table[q][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] == 1 || table[i][j] == 2)
            {
                tmp++;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans;
}