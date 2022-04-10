#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int> > pv;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        pv.push_back({a, b});
    }

    sort(pv.begin(), pv.end());

    for (int i = 0; i < pv.size(); i++)
    {
        cout << pv[i].first << " " << pv[i].second << "\n";
    }
}
