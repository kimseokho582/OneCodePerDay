#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    // for (int x : v)
    //     cout << x << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
}