#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > v(101);
queue<int> q;
int check[101] = {
    0,
};
int n, m;
int ans = 0;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    q.push(1);
    check[1] = 1;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];
            if (check[next] != 1)
            {
                ans++;
                check[next] = 1;
                q.push(next);
            }
        }
    }
    cout << ans;
}