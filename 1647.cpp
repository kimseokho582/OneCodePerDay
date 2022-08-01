#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int table[100001];
vector<pair<int, pair<int, int>>> v;
int n, m;

int Find(int x)
{
    if (table[x] == x)
        return x;
    else
        return table[x] = Find(table[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x != y)
        table[y] = x;
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
    int large = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
        v.push_back({c, {b, a}});
    }
    for (int i = 1; i <= n; i++)
    {
        table[i] = i;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (same(v[i].second.first, v[i].second.second) == false)
        {
            Union(v[i].second.first, v[i].second.second);
            ans = ans + v[i].first;
            large = max(large, v[i].first);
        }
    }
    cout << ans - large;
}