#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> table(1001);
int node[1001];
bool visited[1001];
int n, m;
bool dfs(int x)
{

    for (int i = table[x].first; i <= table[x].second; i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        if (node[i] == -1 || dfs(node[i]))
        {
            node[i] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;

    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        table.clear();

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            table.push_back({a, b});
        }

        fill(node, node + 1001, -1);
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            fill(visited, visited + 1001, false);
            if (dfs(i))
                ans++;
        }

        cout << ans << '\n';
    }
}
