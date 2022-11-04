#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int table[51][51];
int visited[51][51] = {
    0,
};
int virusOrder[11];
int visitedOrder[11];
vector<pair<int, int>> v;
int n, m, zerocnt = 0;
queue<pair<int, int>> q;
int ans = 999999999;
void calc()
{
    int cnt = 0;
    int visitedcnt = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if (table[nx][ny] != 1 && visited[nx][ny] == -1)
                {

                    visited[nx][ny] = visited[x][y] + 1;

                    if (table[nx][ny] == 0)
                    {
                        visitedcnt++;
                        cnt = visited[nx][ny];
                    }

                    q.push({nx, ny});
                }
            }
        }
    }
    if (zerocnt == visitedcnt)
    {
        ans = min(ans, cnt);
    }
}

void order(int num, int cnt)
{

    if (cnt == m)
    {
        memset(visited, -1, sizeof(visited));
        for (int i = 0; i < m; i++)
        {
            int idx = virusOrder[i] - 1;
            q.push({v[idx].first, v[idx].second});
            visited[v[idx].first][v[idx].second] = 0;
        }
        calc();

        return;
    }

    for (int i = num; i <= v.size(); i++)
    {
        if (!visitedOrder[i])
        {
            visitedOrder[i] = 1;
            virusOrder[cnt] = i;
            order(i + 1, cnt + 1);
            visitedOrder[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j];
            if (table[i][j] == 2)
            {
                v.push_back({i, j});
            }
            else if (table[i][j] == 0)
            {
                zerocnt++;
            }
        }
    }
    order(1, 0);
    if (ans == 999999999)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}