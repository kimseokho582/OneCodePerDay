#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int visited[20001] = {
    0,
};
vector<int> table[20001];

int main()
{
    int ans1 = 0, ans2 = 0, ans3 = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        table[a].push_back(b);
        table[b].push_back(a);
    }
    queue<pair<int, int>> q;
    visited[1] = -1;
    for (int i = 0; i < table[1].size(); i++)
    {
        q.push({table[1][i], 1});
        visited[table[1][i]] = 1;
    }

    while (!q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for (int i = 0; i < table[now].size(); i++)
        {
            if (visited[table[now][i]] == 0)
            {
                q.push({table[now][i], cnt + 1});
                visited[table[now][i]] = cnt + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans2 < visited[i])
        {
            ans1 = i;
            ans2 = visited[i];
            ans3 = 1;
        }
        else if (ans2 == visited[i])
        {
            ans3++;
        }
    }
    cout << ans1 << " " << ans2 << " " << ans3;
}