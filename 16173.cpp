#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int table[4][4];
int visited[4][4] = {
    0,
};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (table[x][y] == -1)
        {
            cout << "HaruHaru";
            return 0;
        }
        for (int i = 0; i < 2; i++)
        {
            int nx, ny;
            if (i == 0)
            {
                nx = x + table[x][y];
                ny = y;
            }
            else
            {
                nx = x;
                ny = y + table[x][y];
            }
            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if (visited[nx][ny] == 0)
                {

                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    cout << "Hing";
}