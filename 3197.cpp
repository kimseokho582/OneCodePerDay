#include <iostream>
#include <queue>

using namespace std;

char table[251][251];
int visited[251][251] = {
    0,
};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
int w = 0, l = 0;

void calc(int a, int b)
{
    int tmpw = 0, tmpl = 0;
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        if (table[x][y] == 'v')
        {
            tmpw++;
        }
        else if (table[x][y] == 'k')
        {
            tmpl++;
        }
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (table[nx][ny] != '#' && !visited[nx][ny])
                {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    if (tmpw >= tmpl)
    {
        w += tmpw;
    }
    else
    {
        l += tmpl;
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && table[i][j] != '#')
            {
                calc(i, j);
            }
        }
    }
    cout << l << " " << w;
}