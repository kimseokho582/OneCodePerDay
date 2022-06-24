#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

long long table[1001];
bool cmp(int x, int y)
{
    return to_string(x) > to_string(y);
}

int main()
{
    string ans;
    int n, m;
    cin >> n >> m;
    int repeat = m - n;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    sort(table, table + n);
    for (int i = 0; i < repeat; i++)
    {
        ans += to_string(table[0]);
    }
    for (int i = 0; i < n; i++)
    {
        ans += to_string(table[i]);
    }
    cout << stoll(ans);
}