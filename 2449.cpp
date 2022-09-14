#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int table[201];
int dp[201][201];

int dfs(int s, int e)
{
    if (s == e)
        return 0;
    if (dp[s][e])
        return dp[s][e];
    if (s - 1 == e)
        return table[s] != table[e];

    int tmp = 987654321;
    for (int i = s; i < e; i++)
    {
        tmp = min(tmp, dfs(s, i) + dfs(i + 1, e) + (table[i] != table[e]));
    }
    return dp[s][e] = tmp;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> table[i];
    }
    cout << dfs(1, n);
}