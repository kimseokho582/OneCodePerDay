#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int table[101][101] = {
    0,
};
int visited[101][101] = {
    0,
};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int ans = 0;
int n, m, k;
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
            if (0 < nx && nx <= n && 0 < ny && ny <= m)
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
    ans = max(ans, cnt);
}

int main()
{

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        table[a][b] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (table[i][j] == 1 && visited[i][j] == 0)
            {

                calc(i, j);
            }
        }
    }
    cout << ans;
}