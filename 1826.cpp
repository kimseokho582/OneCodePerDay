#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, less<int>> save;
vector<pair<int, int>> v;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    int dst, oil;
    cin >> dst >> oil;
    int ans = 0;
    int idx = 0;
    sort(v.begin(), v.end());
    while (oil < dst)
    {
        while (v[idx].first <= oil && idx < t)
        {
            save.push(v[idx].second);
            idx++;
        }

        if (save.empty())
        {
            ans = -1;
            break;
        }
        else
        {
            oil += save.top();
            save.pop();
            ans++;
        }
    }

    cout << ans;
}