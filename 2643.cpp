#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int table[101];
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
    {
        return 1;
    }
    else if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a > b ? v.push_back({a, b}) : v.push_back({b, a});
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        table[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[i].first <= v[j].first && v[i].second <= v[j].second)
            {
                table[i] = max(table[j] + 1, table[i]);
            }
        }
        ans = max(ans, table[i]);
    }
    cout << ans;
}