#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int dir[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}};
int table[25][25];
int check[25][25] = {
    0,
};
int n, cnt = 0;
vector<int> ans;
void find(int x, int y)
{
    int tmpCnt = 0;
    queue<pair<int, int> > q;
    q.push({x, y});
    check[x][y] = 1;
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        tmpCnt++;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dir[i][0];
            int ny = yy + dir[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && table[nx][ny] == 1 && check[nx][ny] == 0)
            {
                check[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    ans.push_back(tmpCnt);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            table[i][j] = int(str[j]) - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] == 1 && check[i][j] == 0)
            {
                cnt++;
                find(i, j);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << cnt << '\n';
    for (int x : ans)
        cout << x << '\n';
}