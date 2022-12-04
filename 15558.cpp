#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;
int table[2][200001] = {
    0,
};
int visited[2][200001] = {
    0,
};
int test[1000];

int main()
{
    cin >> n >> k;
    fill(&table[0][0], &table[1][200001], 1);
    for (int i = 0; i < 2; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= n; j++)
        {
            table[i][j] = str[j - 1] - '0';
        }
    }

    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 1}, 0});
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int remove = q.front().second;
        q.pop();
        if (n <= y)
        {
            cout << 1;
            return 0;
        }

        if (table[x][y + 1] == 1)
        {
            if (visited[x][y + 1] == 0)
            {
                q.push({{x, y + 1}, remove + 1});
                visited[x][y + 1] = 1;
            }
        }

        if (table[x][y - 1] == 1 && remove + 1 < y - 1)
        {
            if (visited[x][y - 1] == 0)
            {
                q.push({{x, y - 1}, remove + 1});
                visited[x][y - 1] = 1;
            }
        }

        if (table[!x][y + k] == 1)
        {
            if (visited[!x][y + k] == 0)
            {
                q.push({{!x, y + k}, remove + 1});
                visited[!x][y + k] = 1;
            }
        }
    }
    cout << 0;
}