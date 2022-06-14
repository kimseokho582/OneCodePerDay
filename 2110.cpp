#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> table;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        table.push_back(tmp);
    }
    sort(table.begin(), table.end());
    int l = 0;
    int r = table[n - 1];
    while (l <= r)
    {
        int cnt = 1;
        int now = 0;
        int mid = (l + r) / 2;
        for (int next = 1; next < n; next++)
        {
            if (table[next] - table[now] >= mid)
            {
                now = next;
                cnt++;
            }
        }
        if (cnt >= m)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << r;
}