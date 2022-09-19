#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char table[101][101];
int visited[101][101] = {
    0,
};
int ans = 0;
int ans2 = 0;
int n;
void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    char now = table[a][b];
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
                if (now == table[nx][ny] && visited[nx][ny] == 0)
                {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
    }
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++)
        {
            table[i][j] = tmp[j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0)
            {
                bfs(i, j);
                ans++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] == 'G')
            {
                table[i][j] = 'R';
            }
        }
    }
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0)
            {
                bfs(i, j);
                ans2++;
            }
        }
    }
    cout << ans << " " << ans2;
}
