#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> ans;
int visited[200001];
int n, m;
int main()
{
    for (int i = 0; i <= 100000; i++)
        visited[i] = -1;
    cin >> n >> m;
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = n;
    while (!q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        if (now == m)
        {
            cout << cnt << endl
                 << n << " ";
            int tmp = now;
            while (tmp != n)
            {

                ans.push_back(tmp);
                tmp = visited[tmp];
            }
        }
        q.pop();

        for (int i = 0; i < 3; i++)
        {
            int nnow;
            if (i == 0)
                nnow = now + 1;
            else if (i == 1)
                nnow = now - 1;
            else
                nnow = now * 2;

            if (visited[nnow] == -1)
            {

                if (0 <= nnow && nnow <= 100000)
                {
                    q.push({nnow, cnt + 1});
                    visited[nnow] = now;
                }
            }
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}