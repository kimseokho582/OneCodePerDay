#include <iostream>

using namespace std;

int table[100001];

int find(int x)
{
    if (x == table[x])
    {
        return x;
    }
    return table[x] = find(table[x]);
}

int main()
{
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        table[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int g;
        cin >> g;
        if (!find(g))
        {
            break;
        }
        else
        {
            table[find(g)] = find(find(g) - 1);
            cnt++;
        }
    }
    cout << cnt;
}
