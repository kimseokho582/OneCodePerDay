#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int table[1001][1001];
int visited[1001][1001] = {
    0,
};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;

bool calc(int a, int b)
{

    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n - 1)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (visited[nx][ny] == 0 && table[nx][ny] == 0)
                {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    return false;
}

int main()
{

    cin >> n >> m;
    string str;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            table[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (visited[0][i] == 0 && table[0][i] == 0)
        {

            if (calc(0, i))
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}