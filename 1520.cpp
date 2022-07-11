#include <iostream>

using namespace std;

int table[501][501];
int dp[501][501];

int dir[4][2] = {
    {1, 0},
    {0, 1},
    {0, -1},
    {-1, 0}};
int n, m;

int dfs(int x, int y)
{
    if (x == n - 1 && y == m - 1)
        return 1;
    if (dp[x][y] != -1)
        return dp[x][y];

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            if (table[x][y] > table[nx][ny])
            {

                dp[x][y] = dp[x][y] + dfs(nx, ny);
            }
        }
    }
    return dp[x][y];
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(0, 0);
}