#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int table[101][101];
int visited[101][101] = {
    0,
};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<pair<int, int>> v;

int n;
void divid(int a, int b, int cnt)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    table[a][b] = cnt;

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
                if (table[nx][ny] == -1)
                {
                    q.push({nx, ny});
                    table[nx][ny] = cnt;
                }
            }
        }
    }
}

int bfs(int x)
{
    int rst = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] == x)
            {
                visited[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int na = a + dir[i][0];
                int nb = b + dir[i][1];
                if (0 <= na && na < n && 0 <= nb && nb < n)
                {
                    if (table[na][nb] != 0 && table[na][nb] != x)
                        return rst;
                    else if (table[na][nb] == 0 && visited[na][nb] == 0)
                    {
                        visited[na][nb] = 1;
                        q.push({na, nb});
                    }
                }
            }
        }
        rst++;
    }
}

int main()
{
    int ans = 999999999;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j];
            if (table[i][j])
            {
                table[i][j] = -1;
                v.push_back({i, j});
            }
        }
    }
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] == -1)
            {
                divid(i, j, cnt);
                cnt++;
            }
        }
    }

    for (int i = 1; i < cnt; i++)
    {
        ans = min(ans, bfs(i));
        memset(visited, 0, sizeof(visited));
    }
    cout << ans;
}