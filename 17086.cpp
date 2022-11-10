#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int table[51][51];
int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<pair<int, int>> v;
int n, m;

int calc(int a, int b)
{
    int visited[51][51] = {
        0,
    };
    queue<pair<pair<int, int>, int>> q;
    q.push({{a, b}, 0});
    visited[a][b] = 1;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;

        q.pop();
        if (table[x][y] == 1)
        {
            return cnt;
        }
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (!visited[nx][ny])
                {
                    visited[nx][ny] = 1;
                    q.push({{nx, ny}, cnt + 1});
                }
            }
        }
    }
    return 999999;
}

int main()
{
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
            if (table[i][j] == 0)
            {
                v.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        ans = max(ans, calc(v[i].first, v[i].second));
    }
    cout << ans;
}