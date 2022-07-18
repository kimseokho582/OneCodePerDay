#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[1001];
int visited[201] = {0, 1};
vector<int> trip;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
            {
                v[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        trip.push_back(tmp);
    }

    queue<int> q;
    q.push(trip[0]);
    visited[trip[0]] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size(); i++)
        {
            int tmp = v[now][i];
            if (visited[tmp] == 0)
            {
                q.push(tmp);
                visited[tmp] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (visited[trip[i]] == 0)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}