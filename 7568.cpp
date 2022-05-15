#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int> > v;
bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x > y;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    int idx = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i].first < v[j].first && v[i].second < v[j].second)
                idx++;
        }
        cout << idx << " ";
        idx = 1;
    }
}
