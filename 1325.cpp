#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[10001];
vector<int> ans;
int large = 0;

void bfs(int x)
{
    queue<int> q;
    int visited[10001] = {
        0,
    };
    q.push(x);
    int cnt = 1;
    visited[x] = 1;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];
            if (!visited[next])
            {
                q.push(next);
                cnt++;
                visited[next] = 1;
            }
        }
    }
    if (large < cnt)
    {
        ans.clear();
        ans.push_back(x);
        large = cnt;
    }
    else if (cnt == large)
    {
        ans.push_back(x);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}