#include <iostream>
#include <cmath>

using namespace std;

int table[10001];
int n, m, r, l = 0;

long long calc(int x)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (table[i] <= x)
        {
            sum += table[i];
        }
        else
        {
            sum += x;
        }
    }
    return sum;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
        r = max(r, table[i]);
    }
    cin >> m;
    long long ans = 0;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (calc(mid) <= m)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans;
}