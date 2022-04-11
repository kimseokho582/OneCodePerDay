#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> pv;

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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        pv.push_back({a, b});
    }

    sort(pv.begin(), pv.end(), cmp);
    for (int i = 0; i < pv.size(); i++)
    {
        cout << pv[i].first << " " << pv[i].second << "\n";
    }
}