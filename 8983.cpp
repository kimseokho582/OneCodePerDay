#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int table[100001];

int main()
{
    int n, m, len;
    cin >> n >> m >> len;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }

    sort(table, table + n);
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (abs(table[mid] - a) + b <= len)
            {
                ans++;
                break;
            }
            else
            {
                if (table[mid] <= a)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
    }
    cout << ans;
}
