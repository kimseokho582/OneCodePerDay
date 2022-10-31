#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int table[501][501];
int visited[501][501];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ans = 0;
int maxsize = 0;
int n, m;

void calc(int a, int b)
{
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (table[nx][ny] == 1 && visited[nx][ny] == 0)
                {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                    cnt++;
                }
            }
        }
    }
    ans++;
    maxsize = max(maxsize, cnt);
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (table[i][j] == 1 && visited[i][j] == 0)
            {
                calc(i, j);
            }
        }
    }
    cout << ans << "\n"
         << maxsize;
}