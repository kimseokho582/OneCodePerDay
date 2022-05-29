#include <iostream>

using namespace std;

int table[11];
int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    while (k)
    {
        ans += k / table[--n];
        k %= table[n];
    }
    cout << ans;
}