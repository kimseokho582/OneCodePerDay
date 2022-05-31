#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, ans = 0;
    int table[100001];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    sort(table, table + n);
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, table[i] * (n - i));
    }
    cout << ans;
}