#include <iostream>
#include <cmath>
using namespace std;

long long table[100001];
int main()
{
    int n, m, ans = 987654321;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    int s = 0, e = 0, total = table[0];
    while (s <= e && e < n)
    {
        if (total >= m)
            ans = min(ans, e - s + 1);

        if (total < m)
        {
            e++;
            total += table[e];
        }
        else
        {
            total -= table[s];
            s++;
        }
    }
    if (ans == 987654321)
        cout << 0;
    else
        cout << ans;
}