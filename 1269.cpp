#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, m;
int num = 0;

void calc(int x)
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] == x)
        {

            num++;
            return;
        }
        if (v[mid] <= x)
        {

            l = mid + 1;
        }
        else
        {

            r = mid - 1;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        calc(tmp);
    }
    cout << n + m - 2 * num;
}