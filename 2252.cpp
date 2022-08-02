#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[32001];
int table[32001] = {
    0,
};
queue<int> q;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        table[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (table[i] == 0)
        {
            q.push(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int j = 0; j < v[x].size(); j++)
        {
            table[v[x][j]]--;
            if (table[v[x][j]] == 0)
            {
                q.push(v[x][j]);
            }
        }
    }
}