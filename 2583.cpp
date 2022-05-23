#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector<int> v;
int table[101][101] = {
    0,
};
int dir[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

void calc(int a, int b)
{
    queue<pair<int, int> > q;
    int cnt = 0;
    q.push({a, b});
    table[a][b] = 1;
    cnt++;
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
                if (table[nx][ny] == 0)
                {
                    q.push({nx, ny});
                    table[nx][ny] = 1;
                    cnt++;
                }
            }
        }
    }
    v.push_back(cnt);
}

int main()
{

    cin >> m >> n >> k;
    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; j++)
        {
            for (int q = y1; q < y2; q++)
            {
                table[j][q] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (table[i][j] == 0)
            {
                ans++;
                calc(i, j);
            }
        }
    }
    cout << ans << "\n";
    sort(v.begin(), v.end());
    for (int x : v)
        cout << x << " ";
}