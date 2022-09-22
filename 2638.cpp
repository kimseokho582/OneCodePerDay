#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int n, m;
int table[101][101];
bool flag = true;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void cheese()
{
    int visited[101][101] = {
        0,
    };
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = -1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        // cout << x << " " << y << endl;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (visited[nx][ny] == 0)
                {
                    if (table[nx][ny] == 0)
                    {
                        q.push({nx, ny});
                        visited[nx][ny] = -1;
                    }
                }
                if (table[nx][ny] == 1)
                {
                    flag = true;
                    visited[nx][ny]++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] >= 2)
            {
                table[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
        }
    }
    while (flag)
    {
        flag = false;
        cheese();
        ans++;
    }
    cout << ans - 1;
}