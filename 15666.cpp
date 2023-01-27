#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int table[10];
int ans[10];
bool visited[10];

void calc(int num, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    int tmp = -1;
    for (int i = num; i < n; i++)
    {
        if (tmp != table[i])
        {
            tmp = table[i];
            ans[cnt] = table[i];
            visited[i] = true;
            calc(i, cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    sort(table, table + n);
    calc(0, 0);
}