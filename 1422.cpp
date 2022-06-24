#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

string table[1001];
bool cmp(string x, string y)
{
    return stoi(x) > stoi(y);
}

bool cmp2(string x, string y)
{
    return x + y > y + x;
}

int main()
{
    string ans;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    sort(table, table + n, cmp);
    for (int i = n; i < m; i++)
    {
        table[i] = table[0];
    }
    sort(table, table + m, cmp2);
    for (int i = 0; i < m; i++)
    {
        ans += table[i];
    }

    cout << ans;
}