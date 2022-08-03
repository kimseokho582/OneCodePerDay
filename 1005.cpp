#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ans[1001] = {
            0,
        };
        vector<int> v[1001];
        int time[1001] = {
            0,
        };
        int table[1001] = {
            0,
        };
        int dst;
        for (int i = 1; i <= n; i++)
        {
            cin >> time[i];
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            table[b]++;
        }
        cin >> dst;
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (table[i] == 0)
            {
                q.push(i);
                ans[i] = time[i];
            }
        }
        while (q.empty() == 0)
        {
            int now = q.front();
            q.pop();

            for (int i = 0; i < v[now].size(); i++)
            {
                int next = v[now][i];

                ans[next] = max(ans[next], ans[now] + time[next]);
                table[next]--;
                if (table[next] == 0)
                    q.push(next);
            }
        }
        cout << ans[dst] << "\n";
    }
}