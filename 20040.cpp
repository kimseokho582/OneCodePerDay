#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int table[1000001];
vector<pair<int, int>> v;

int Find(int x)
{
    if (table[x] == x)
        return x;
    else
        return table[x] = Find(table[x]);
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
    {
        return true;
    }
    else
    {

        table[y] = x;
        return false;
    }
}

int main()
{

    int n, m;
    int ans = 0;
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        table[i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if (Union(a, b))
        {
            ans = i;
            break;
        }
    }
    cout << ans;
}