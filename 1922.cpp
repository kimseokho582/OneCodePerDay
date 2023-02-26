#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 999999999

int parent[1001];
vector<pair<int, pair<int, int>>> v;
int n, m;
int ans;
bool flag = false;

int find(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
    flag = false;
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    parent[x] = y;
    flag = true;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++)
    {
        merge(v[i].second.first, v[i].second.second);
        if (flag)
            ans += v[i].first;
    }
    cout << ans;
}