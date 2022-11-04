#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int table[51][51];
int cmp[51][51];
int visited[51][51] = {
    0,
};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, l, r;
void calc(int a, int b)
{

    queue<pair<int, int>> q;
    vector<pair<int, int>> mergeIndex;
    int mergeCnt = table[a][b];
    q.push({a, b});
    mergeIndex.push_back({a, b});
    visited[a][b] = 1;

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
                if (visited[nx][ny] == 0 && l <= abs(table[x][y] - table[nx][ny]) && abs(table[x][y] - table[nx][ny]) <= r)
                {

                    q.push({nx, ny});
                    mergeIndex.push_back({nx, ny});
                    mergeCnt += table[nx][ny];
                    visited[nx][ny] = 1;
                }
            }
        }
    }

    for (int i = 0; i < mergeIndex.size(); i++)
    {
        table[mergeIndex[i].first][mergeIndex[i].second] = mergeCnt / mergeIndex.size();
    }
}

int main()
{
    int ans = 0;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j];
        }
    }
    int flag = 1;
    while (flag == 1)
    {
        flag = 0;
        ans++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cmp[i][j] = table[i][j];
            }
        }

        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    calc(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (table[i][j] != cmp[i][j])
                {
                    flag = 1;
                }
            }
        }
    }
    cout << ans - 1;
}