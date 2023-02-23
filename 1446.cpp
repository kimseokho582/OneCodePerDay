#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int table[10001];

typedef pair<int, pair<int, int>> pp;

priority_queue<pp, vector<pp>, greater<pp>> q;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int s, e, n;
        cin >> s >> e >> n;
        q.push({e, {s, n}});
    }

    table[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        table[i] = table[i - 1] + 1;
        while (!q.empty() && q.top().first == i)
        {
            table[i] = min(table[i], q.top().second.second + table[q.top().second.first]);
            q.pop();
        }
    }
    cout << table[m];
}