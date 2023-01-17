#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
char table[51][51];
int watertable[51][51];
int visited[51][51];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
pair<int, int> start;
queue<pair<int, int>> water;
int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {

        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            watertable[i][j] = 1000;
            table[i][j] = str[j];
            if (table[i][j] == 'S')
            {
                start = {i, j};
            }
            if (table[i][j] == '*')
            {
                watertable[i][j] = 0;
                water.push({i, j});
            }
        }
    }

    while (!water.empty())
    {
        int size = water.size();
        for (int i = 0; i < size; i++)
        {
            int wx = water.front().first;
            int wy = water.front().second;
            water.pop();

            for (int i = 0; i < 4; i++)
            {
                int nwx = wx + dir[i][0];
                int nwy = wy + dir[i][1];
                if (0 <= nwx && nwx < n && 0 <= nwy && nwy < m)
                {
                    if (table[nwx][nwy] == '.')
                    {
                        if (watertable[nwx][nwy] > watertable[wx][wy] + 1)
                        {
                            watertable[nwx][nwy] = watertable[wx][wy] + 1;
                            water.push({nwx, nwy});
                        }
                    }
                }
            }
        }
    }

    queue<pair<pair<int, int>, int>> go;
    go.push({{start.first, start.second}, 0});
    while (!go.empty())
    {

        int x = go.front().first.first;
        int y = go.front().first.second;
        int cnt = go.front().second;

        visited[x][y] = 1;
        go.pop();
        if (table[x][y] == 'D')
        {
            cout << cnt;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (table[nx][ny] != 'X' && visited[nx][ny] == 0 && watertable[nx][ny] > cnt + 1)
                {

                    go.push({{nx, ny}, cnt + 1});
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    cout << "KAKTUS";
}