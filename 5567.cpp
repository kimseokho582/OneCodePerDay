#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int visited[501] = {
    0,
};
vector<int> v[501];

int main()
{
    int ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = 1;

    while (!q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        if (cnt > 2)
        {
            break;
        }
        else
        {
            ans++;
        }
        q.pop();
        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];
            if (!visited[next])
            {
                q.push({next, cnt + 1});
                visited[next] = 1;
            }
        }
    }
    cout << ans - 1;
}