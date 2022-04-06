#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    stable_sort(v.begin(), v.end());
    // for (int x : v)cout << x << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
}