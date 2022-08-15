#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

char table[51][51];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
int BFS(int x, int y)
{
    int visited[51][51] = {
        0,
    };
    int rtn = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, 0});
    visited[x][y] = 1;

    while (!q.empty())
    {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int na = a + dir[i][0];
            int nb = b + dir[i][1];
            if (table[na][nb] == 'L' && visited[na][nb] == 0)
            {
                if (0 <= na && na < n && 0 <= nb && nb < m)
                {
                    q.push({{na, nb}, cnt + 1});
                    visited[na][nb] = 1;
                }
            }
        }
        rtn = max(cnt, rtn);
    }
    return rtn;
}

int main()
{

    cin >> n >> m;
    int ans = 0;
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
            if (table[i][j] == 'L')
            {
                ans = max(ans, BFS(i, j));
            }
        }
    }
    cout << ans;
}