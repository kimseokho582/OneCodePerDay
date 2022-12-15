#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[100001] = {
    0,
};

int main()
{
    int n, m;
    cin >> n >> m;
    int time = 999999999;
    int ans = 0;
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = 1;
    while (!q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        visited[now] = 1;

        if (time < cnt)
            break;

        if (now == m)
        {
            time = cnt;
            ans++;
        }

        if (now + 1 < 100001 && visited[now + 1] == 0)
        {

            q.push({now + 1, cnt + 1});
        }
        if (0 <= now - 1 && visited[now - 1] == 0)
        {

            q.push({now - 1, cnt + 1});
        }
        if (now * 2 < 100001 && visited[now * 2] == 0)
        {

            q.push({now * 2, cnt + 1});
        }
    }
    cout << time << " " << ans;
}