#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int table[101][101];
int dij[101][101];
int n, m;
int dir[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

void calc()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    dij[0][0] = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || ny < 0 || m <= nx || n <= ny)
                continue;

            if (table[nx][ny] == 1)
            {
                if (dij[nx][ny] > dij[x][y] + 1)
                {
                    dij[nx][ny] = dij[x][y] + 1;
                    q.push({nx, ny});
                }
            }
            else if (table[nx][ny] == 0)
            {
                if (dij[nx][ny] > dij[x][y])
                {
                    dij[nx][ny] = dij[x][y];
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    string s;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            dij[i][j] = 987654321;
            table[i][j] = s[j] - '0';
        }
    }
    calc();
    cout << dij[m - 1][n - 1];
}