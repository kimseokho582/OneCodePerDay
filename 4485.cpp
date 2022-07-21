#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, n;
    while (1)
    {
        cin >> n;
        if (!n)
            return 0;
        int table[126][126] = {
            0,
        };
        int dij[126][126];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> table[i][j];
                dij[i][j] = 987654321;
            }
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        dij[0][0] = table[0][0];

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx < 0 || ny < 0 || n <= nx || n <= ny)
                    continue;

                if (dij[nx][ny] > table[nx][ny] + dij[x][y])
                {
                    dij[nx][ny] = table[nx][ny] + dij[x][y];

                    q.push({nx, ny});
                }
            }
        }

        cout << "Problem " << t << ": " << dij[n - 1][n - 1] << "\n";
        t++;
    }
}