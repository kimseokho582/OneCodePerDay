#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
char table[51][51];
int height[51][51];
int visited[51][51];
int dir[8][2] = {{1, 0}, {1, 1}, {1, -1}, {-1, 0}, {-1, 1}, {-1, -1}, {0, 1}, {0, -1}};
vector<int> heightList;
int home = 0;
int cnt = 0;
pair<int, int> office;

void calc(int s, int e)
{
    queue<pair<int, int>> q;
    q.push({office.first, office.second});
    visited[office.first][office.second] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if (visited[nx][ny] == 0)
                {
                    if (heightList[s] <= height[nx][ny] && height[nx][ny] <= heightList[e])
                    {
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                        if (table[nx][ny] == 'K')
                            cnt++;
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            table[i][j] = str[j];
            if (table[i][j] == 'K')
            {
                home++;
            }

            if (table[i][j] == 'P')
            {
                office = {i, j};
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> height[i][j];
            heightList.push_back(height[i][j]);
        }
    }

    sort(heightList.begin(), heightList.end());
    heightList.erase(unique(heightList.begin(), heightList.end()), heightList.end());
    int s = 0, e = 0, ans = 999999999;
    while (true)
    {
        if (heightList[e] < height[office.first][office.second])
        {
            e++;
            continue;
        }
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        calc(s, e);

        if (home != cnt)
        {
            e++;
            if (heightList.size() <= e)
            {
                break;
            }
        }
        else
        {

            int tmp = heightList[e] - heightList[s];
            ans = min(ans, tmp);
            s++;
            if (height[office.first][office.second] < heightList[s])
            {
                break;
            }
            if (heightList.size() <= s)
            {
                break;
            }
        }
    }
    cout << ans;
}