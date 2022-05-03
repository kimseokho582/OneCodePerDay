#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int main()
{
    int n;
    cin >> n;
    vector<long> v;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int term = v[1] - v[0];
    for (int i = 1; i < n - 1; i++)
    {
        int next = v[i + 1] - v[i];

        term = gcd(term, next);
    }
    cout << (v[n - 1] - v[0]) / term - n + 1;
}