#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[1001];
int table[1001] = {
    0,
};
vector<int> ans;
queue<int> q;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        int x, y;
        cin >> x;
        for (int j = 0; j < tmp - 1; j++)
        {
            cin >> y;
            v[x].push_back(y);
            table[y]++;
            x = y;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (table[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {

        int x = q.front();
        ans.push_back(x);

        q.pop();
        for (int j = 0; j < v[x].size(); j++)
        {
            table[v[x][j]]--;
            if (table[v[x][j]] == 0)
            {
                q.push(v[x][j]);
            }
        }
    }
    if (ans.size() != n)
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << "\n";
        }
    }
}