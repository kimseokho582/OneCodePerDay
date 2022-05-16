#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int table[1000][1000];
int check[1000][1000][2];
int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1},
};
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            int num = tmp[j] - '0';
            table[i][j] = num;
        }
    }

    queue<vector<int> > q;
    q.push({0, 0, 1, 0});
    check[0][0][0] = 1;

    while (!q.empty())
    {
        int x = q.front()[0];
        int y = q.front()[1];
        int val = q.front()[2];
        int bk = q.front()[3];
        if (x == n - 1 && y == m - 1)
        {
            cout << val;
            return 0;
        }
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (table[nx][ny] == 1 && bk == 0)
                {
                    check[nx][ny][bk + 1] = 1;
                    q.push({nx, ny, val + 1, bk + 1});
                }
                else if (table[nx][ny] == 0 && check[nx][ny][bk] == 0)
                {
                    check[nx][ny][bk] = 1;
                    q.push({nx, ny, val + 1, bk});
                }
            }
        }
    }
    cout << -1;
}
