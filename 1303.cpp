#include <iostream>
#include <queue>

using namespace std;
char table[101][101];
int visited[101][101] = {
    0,
};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
int white = 0, blue = 0;
void calc(int a, int b)
{
    int tmpw = 0;
    int tmpb = 0;
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    char soldier = table[a][b];
    if (soldier == 'W')
    {
        tmpw++;
    }
    else
    {
        tmpb++;
    }
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (!visited[nx][ny] && table[nx][ny] == soldier)
                {
                    q.push({nx, ny});
                    if (soldier == 'W')
                    {
                        tmpw++;
                    }
                    else
                    {
                        tmpb++;
                    }
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    white += (tmpw * tmpw);
    blue += (tmpb * tmpb);
}

int main()
{
    cin >> m >> n;
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
            if (!visited[i][j])
            {

                calc(i, j);
            }
        }
    }

    cout << white << " " << blue;
}