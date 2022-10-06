#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int visited[31] = {
    0,
};
char table[21][21];
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int ans = 0;
int n, m;
void dfs(int x, int y, int cnt)
{
    ans = max(cnt, ans);
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            if (visited[table[nx][ny] - 0] == 0)
            {
                visited[table[nx][ny] - 0] = 1;
                dfs(nx, ny, cnt + 1);
                visited[table[nx][ny] - 0] = 0;
            }
        }
    }
}

int main()
{

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
    visited[table[0][0] - 0] = 1;
    dfs(0, 0, 1);
    cout << ans;
}