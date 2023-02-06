#include <iostream>

using namespace std;

long long table[101];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        table[tmp % m]++;
    }

    long long ans = 0;
    if (table[0])
        ans++;

    for (int i = 1; i * 2 <= m; i++)
    {
        if (i * 2 == m)
            ans += (table[i] > 0);
        else
            ans += max(table[i], table[m - i]);
    }
    cout << ans;
}