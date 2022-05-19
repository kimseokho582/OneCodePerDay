#include <iostream>
#include <cstring>
using namespace std;

int table[100001];
int visited[100001] = {
    0,
};
int check[100001] = {
    0,
};
int ans = 0;
void calc(int x)
{
    visited[x] = 1;
    int next = table[x];
    if (visited[next] == 0)
    {
        calc(next);
    }
    else if (check[next] == 0)
    {

        for (int i = next; i != x; i = table[i])
        {
            ans++;
        }
        ans++;
    }
    check[x] = 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> table[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
            {
                calc(i);
            }
        }
        cout << n - ans << "\n";
        ans = 0;
        memset(check, false, sizeof(check));
        memset(visited, false, sizeof(visited));
    }
}