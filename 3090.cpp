#include <iostream>
#include <algorithm>
using namespace std;

int table[100001];
long long tmp[100001];
int n, t;
bool calc(int diff)
{
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        tmp[i] = table[i];
    }
    for (int i = 0; i < (n - 1); i++)
    {
        if (tmp[i + 1] - tmp[i] > diff)
        {

            cnt += (tmp[i + 1] - (tmp[i] + diff));
            tmp[i + 1] = diff + tmp[i];
        }
    }

    for (int i = (n - 1); i > 0; i--)
    {
        if (tmp[i - 1] - tmp[i] > diff)
        {
            cnt += (tmp[i - 1] - (tmp[i] + diff));
            tmp[i - 1] = diff + tmp[i];
        }
    }

    if (cnt <= t)
    {

        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> t;
    int l = 0, r;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
        r = max(r, table[i]);
    }

    int ans[100001];
    while (l <= r)
    {

        int m = (l + r) / 2;
        if (calc(m))
        {
            for (int i = 0; i < n; i++)
            {
                ans[i] = tmp[i];
            }
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
