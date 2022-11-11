#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char table[251][251];
int visited[251][251] = {
    0,
};
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;
int sheep = 0, wolf = 0;

void calc(int a, int b)
{
    int tmps = 0, tmpw = 0;
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (table[x][y] == 'o')
        {
            tmps++;
        }
        else if (table[x][y] == 'v')
        {
            tmpw++;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (visited[nx][ny] == 0)
                {
                    if (table[nx][ny] != '#')
                    {
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    if (tmps > tmpw)
    {
        sheep += tmps;
    }
    else
    {
        wolf += tmpw;
    }
}

int main()
{
    string str;
    cin >> n >> m;
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
            if (visited[i][j] == 0)
            {
                if (table[i][j] != '#')
                {
                    calc(i, j);
                }
            }
        }
    }
    cout << sheep << " " << wolf;
}