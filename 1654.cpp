#include <iostream>
#include <algorithm>
using namespace std;

long long table[10001];
long long n, m;
bool calc(int x)
{
    long long tmp = 0;
    for (int i = 0; i < n; i++)
    {
        tmp += (table[i] / x);
    }
    if (tmp >= m)
        return true;
    else
        return false;
}

int main()
{

    cin >> n >> m;
    long long r = 0, l = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
        r = max(r, table[i]);
    }
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (calc(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans;
}
