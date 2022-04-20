#include <iostream>
#include <algorithm>

using namespace std;

int table[21];
int sum[21];
int n, s, ans = 0;

void calc(int sidx, int tidx, int limit)
{
    if (sidx == limit)
    {
        int tmp = 0;
        for (int i = 0; i < sidx; i++)
        {
            tmp += sum[i];
        }
        if (tmp == s)
            ans++;

        return;
    }

    for (int i = tidx; i < n; i++)
    {
        sum[sidx] = table[i];
        calc(sidx + 1, i + 1, limit);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    sort(table, table + n);

    for (int i = 1; i <= n; i++)
    {
        calc(0, 0, i);
    }
    cout << ans;
}