#include <iostream>
#include <cmath>

using namespace std;
int table[1000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= m; i++)
    {
        table[i] = i;
    }

    for (int i = 2; i <= m; i++)
    {
        for (int j = i + i; j <= m; j += i)
        {
            if (table[j] == 0)
                continue;
            table[j] = 0;
        }
    }

    for (int i = n; i <= m; i++)
    {
        if (table[i])
            cout << i << "\n";
    }
}