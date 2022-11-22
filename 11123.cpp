#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int t;
int n, m;

char table[101][101];
int visited[101][101] = {
    0,
};
int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int ans = 0;
void calc(int a, int b)
{
    ans++;
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
                if (visited[nx][ny] == 0 && table[nx][ny] == '#')
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
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < m; j++)
            {
                table[i][j] = str[j];
            }
        }
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 0 && table[i][j] == '#')
                {
                    calc(i, j);
                }
            }
        }
        cout << ans << "\n";
    }
}