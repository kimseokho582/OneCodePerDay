#include <iostream>

using namespace std;
int table[1001];
int visited[1001];
int ans = 0;
int t;

void dfs(int now)
{
    if (visited[now] == 1)
    {
        ans++;
        return;
    }
    visited[now] = 1;

    dfs(table[now]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        fill(&table[0], &table[1001], 0);
        fill(&visited[0], &visited[1001], 0);
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> table[i];
        }
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i);
            }
        }
        cout << ans << "\n";
    }
}