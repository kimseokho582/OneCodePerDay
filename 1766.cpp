#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int table[32001];
vector<int> v[32001];

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
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (table[i] == 0)
        {
            pq.push(i);
        }
    }
    while (!pq.empty())
    {
        int now = pq.top();
        pq.pop();
        cout << now << " ";
        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];
            table[next]--;
            if (table[next] == 0)
                pq.push(next);
        }
    }
}