#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int check[1000001];
int table[6][6];
int ans = 0;

void dfs(int x, int y, int sum, int cnt)
{
    if (cnt == 6)
    {
        if (!check[sum])
        {
            check[sum] = 1;
            ans++;
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (0 <= nx && nx < 5 && 0 <= ny && ny < 5)
        {
            dfs(nx, ny, sum * 10 + table[nx][ny], cnt + 1);
        }
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dfs(i, j, table[i][j], 1);
        }
    }
    cout << ans;
}