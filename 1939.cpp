#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v[100001];
bool visited[100001];
int s, e;
bool calc(int cost)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == e)
            return true;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int nextcost = v[cur][i].second;
            if (!visited[next] && cost <= nextcost)
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int r = 0, l = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
        r = max(c, r);
    }
    cin >> s >> e;
    while (l <= r)
    {
        fill(visited, visited + 100001, false);
        int m = (l + r) / 2;
        if (calc(m))
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << r;
}