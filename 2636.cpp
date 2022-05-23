#include <iostream>
#include <queue>
using namespace std;

int table[101][101];
int visited[101][101] = {
    0,
};
int dir[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

int main()
{
    int n, m;
    cin >> n >> m;
    int cheeze = 0;
    int cnt = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
        }
    }
    queue<pair<int, int> > q;
    queue<pair<int, int> > edge;
    q.push({0, 0});
    visited[0][0] = 1;
    while (!q.empty())
    {

        cheeze = q.size();
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
                    if (visited[nx][ny] == 0)
                    {
                        if (table[nx][ny] == 0)
                        {
                            q.push({nx, ny});
                        }
                        else if (table[nx][ny] == 1)
                        {
                            edge.push({nx, ny});
                        }
                        visited[nx][ny] = 1;
                    }
                }
            }
        }
        while (!edge.empty())
        {
            q.push(edge.front());
            edge.pop();
        }
        cnt++;
    }
    cout << cnt << "\n"
         << cheeze;
}