#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int table[100001];
int visited[100001] = {
    0,
};
int n, m;

int main()
{
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> table[i];
    }
    cin >> m;
    queue<int> q;
    q.push(m);
    visited[m] = 1;
    while (!q.empty())
    {
        int now = q.front();
        int pre = now - table[now];
        int next = now + table[now];
        q.pop();
        ans++;
        if (pre >= 1 && visited[pre] == 0)
        {
            q.push(pre);
            visited[pre] = 1;
        }

        if (next <= n && visited[next] == 0)
        {
            q.push(next);
            visited[next] = 1;
        }
    }
    cout << ans;
}