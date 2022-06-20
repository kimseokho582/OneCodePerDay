#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> pq;
pair<int, int> j[300001];
int b[300001];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> j[i].first >> j[i].second;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(j, j + n);
    sort(b, b + m);
    int idx = 0;
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        while (idx < n && b[i] >= j[idx].first)
        {
            pq.push(j[idx].second);
            idx++;
        }
        if (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
}