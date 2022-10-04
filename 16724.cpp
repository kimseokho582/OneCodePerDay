#include <iostream>
#include <cstring>
using namespace std;

char table[1001][1001];
int visited[1001][1001] = {
    0,
};
int n, m;
int ans = 0;
void dfs(int x, int y)
{
    visited[x][y] = 1;
    int nx, ny;
    if (table[x][y] == 'U')
    {
        nx = x - 1;
        ny = y;
    }
    else if (table[x][y] == 'D')
    {
        nx = x + 1;
        ny = y;
    }
    else if (table[x][y] == 'L')
    {
        nx = x;
        ny = y - 1;
    }
    else
    {
        nx = x;
        ny = y + 1;
    }

    if (0 <= nx && nx < n && 0 <= ny && ny < m)
    {

        if (visited[nx][ny] == 1)
        {
            ans++;
        }

        if (!visited[nx][ny])
        {
            dfs(nx, ny);
        }
    }
    visited[x][y] = 2;
}

int main()
{

    cin >> n >> m;

    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            table[i][j] = str[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])

                dfs(i, j);
        }
    }

    cout << ans;
}