#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int table[22][22];
int ans = 999999999;
int n;
bool divided[22];

void DFS(int cnt, int next)
{
    if (cnt == n / 2)
    {
        int s = 0, l = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (divided[i] && divided[j])
                    s += table[i][j];
                if (!divided[i] && !divided[j])
                    l += table[i][j];
            }
        }
        int tmp = abs(s - l);
        ans = min(tmp, ans);
        return;
    }
    for (int i = next; i < n; i++)
    {
        divided[i] = true;
        DFS(cnt + 1, i + 1);
        divided[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> table[i][j];
        }
    }
    DFS(0, 1);
    cout << ans;
}