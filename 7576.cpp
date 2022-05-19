#include <iostream>
#include <queue>
using namespace std;

int table[1001][1001];
int dir[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};
queue<pair<int, int> > check;
int ans = 0;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;
    int zeroCnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> table[i][j];
            if (table[i][j] == 1)
            {
                check.push(make_pair(i, j));
            }
            if (table[i][j] == 0)
            {
                zeroCnt++;
            }
        }
    }
    int x, y;
    while (!check.empty())
    {
        int cnt = check.size();
        for (int i = 0; i < cnt; i++)
        {
            x = check.front().first;
            y = check.front().second;
            check.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if (0 <= nx && nx < N && 0 <= ny && ny < M)
                {
                    if (table[nx][ny] == 0)
                    {
                        check.push({nx, ny});
                        table[nx][ny] = 1;
                        zeroCnt--;
                    }
                }
            }
        }
        ans++;
    }

    if (zeroCnt)
    {
        cout << -1;
    }
    else
    {
        cout << ans - 1;
    }
}
