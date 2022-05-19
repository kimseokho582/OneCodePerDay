#include <iostream>
#include <queue>

using namespace std;

queue<pair<pair<int, int>, int> > q;
int map[101][101][101] = {0};
int dir[6][3] = {
    {1, 0, 0},
    {-1, 0, 0},
    {0, 1, 0},
    {0, -1, 0},
    {0, 0, 1},
    {0, 0, -1},
};

int main()
{
    int m, n, h;
    cin >> m >> n >> h;
    int zeroCnt = 0;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> map[i][j][k];
                if (map[i][j][k] == 1)
                {
                    q.push(make_pair(make_pair(i, j), k));
                }
                else if (map[i][j][k] == 0)
                {
                    zeroCnt++;
                }
            }
        }
    }

    int ans = -1;

    while (!q.empty())
    {
        int size = q.size();
        ++ans;
        while (size--)
        {
            pair<pair<int, int>, int> now = q.front();
            q.pop();

            for (int i = 0; i < 6; i++)
            {
                int qx, qy, qz;
                qx = now.first.second + dir[i][0];
                qy = now.first.first + dir[i][1];
                qz = now.second + dir[i][2];

                if (qx < 0 || qx >= m || qy < 0 || qy >= n || qz < 0 || qz >= h)
                    continue;
                if (map[qy][qx][qz] == 0)
                {
                    map[qy][qx][qz] = 1;
                    q.push(make_pair(make_pair(qy, qx), qz));
                    zeroCnt--;
                }
            }
        }
    }

    if (zeroCnt == 0)
    {
        cout << ans;
    }
    else
    {
        cout << -1;
    }
    return 0;
}
