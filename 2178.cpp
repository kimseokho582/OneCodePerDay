#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int dir[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}};
int table[101][101];
int check[101][101] = {
    0,
};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 1; j <= m; j++)
        {
            table[i][j] = tmp[j - 1] - '0';
        }
    }

    queue<pair<pair<int, int>, int> > q;

    q.push({{1, 1}, 1});
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int val = q.front().second;
        q.pop();
        if (x == n && y == m)
        {
            cout << val;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && check[nx][ny] == 0 && table[nx][ny] == 1)
            {
                check[nx][ny] = 1;
                q.push({{nx, ny}, val + 1});
            }
        }
    }
}