#include <iostream>
#include <algorithm>

using namespace std;

int n;
int table[20][20];
int dirs[3][2] = {{0, 1}, {1, 0}, {1, 1}};
int ans = 0;

void dfs(int x, int y, int dir)
{
    if (x == n && y == n)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if ((dir == 0 && i == 1) || (dir == 1 && i == 0))
            continue;

        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        if (nx < 1 || nx > n || ny < 1 || ny > n || table[nx][ny] == 1)
            continue;
        if (i == 2 && (table[x + 1][y] == 1 || table[x][y + 1] == 1))
            continue;
        dfs(nx, ny, i);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> table[i][j];
        }
    }
    dfs(1, 2, 0);
    cout << ans;
}