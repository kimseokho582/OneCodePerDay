#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> v;
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    long long l = 0, r = v[n - 1] * m;
    long long ans;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += mid / v[i];
        }

        if (sum < m)
        {
            l = mid + 1;
        }
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans;
}