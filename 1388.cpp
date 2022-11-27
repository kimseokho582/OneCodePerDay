#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
char table[51][51];
int visited[51][51] = {
    0,
};
int n, m;

void calc(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int nx, ny;
        if (table[x][y] == '-')
        {
            nx = x;
            ny = y + 1;
        }
        else
        {
            nx = x + 1;
            ny = y;
        }
        if (0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            if (table[x][y] == table[nx][ny])
            {
                if (visited[nx][ny] == 0)
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
    int ans = 0;
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
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0)
            {
                calc(i, j);
                ans++;
            }
        }
    }
    cout << ans;
}