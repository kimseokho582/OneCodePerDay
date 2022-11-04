#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[300000];
int visited[300001] = {
    0,
};

int main()
{
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    queue<pair<int, int>> q;
    q.push({x, 0});
    visited[x] = -1;
    while (!q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];
            if (visited[next] == 0)
            {
                q.push({next, cnt + 1});
                visited[next] = cnt + 1;
            }
        }
    }
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == k)
        {
            flag = 1;
            cout << i << "\n";
        }
    }
    if (flag == 0)
    {
        cout << -1;
    }
}