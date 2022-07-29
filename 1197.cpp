#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int p[10002];
vector<pair<int, pair<int, int>>> v;

int Find(int x)
{
    if (p[x] == x)
        return x;
    else
        return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x != y)
        p[y] = x;
}

bool same(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y)
        return true;
    else
        return false;
}

int main()
{
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        if (same(v[i].second.first, v[i].second.second) == false)
        {
            Union(v[i].second.first, v[i].second.second);
            ans = ans + v[i].first;
        }
    }
    cout << ans;
}