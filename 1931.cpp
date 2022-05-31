#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > v;

bool cmp(pair<int, int> x, pair<int, int> y)
{
    if (x.second == y.second)
    {
        return x.first < y.first;
    }
    else
    {
        return x.second < y.second;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);

    int endtime = v[0].second, ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (endtime <= v[i].first)
        {
            endtime = v[i].second;
            ans++;
        }
    }
    cout << ans;
}