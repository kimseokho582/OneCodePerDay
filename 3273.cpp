#include <iostream>
#include <algorithm>
using namespace std;

int table[100001];

int main()
{
    int n, m, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    cin >> m;
    sort(table, table + n);
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        if (table[l] + table[r] == m)
        {
            ans++;
            l++;
            r--;
        }
        else if (table[l] + table[r] > m)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    cout << ans;
}