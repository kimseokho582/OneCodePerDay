#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int table[51][51];
int dij[51][51];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            table[i][j] = str[j] - '0';
            dij[i][j] = 987654321;
        }
    }
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
            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if (table[nx][ny] == 1)
                {
                    if (dij[x][y] < dij[nx][ny])
                    {
                        dij[nx][ny] = dij[x][y];
                        q.push({nx, ny});
                    }
                }
                else
                {
                    if (dij[x][y] + 1 < dij[nx][ny])
                    {
                        dij[nx][ny] = dij[x][y] + 1;

                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    cout << dij[n - 1][n - 1];
}