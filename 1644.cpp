#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int table[4000001];
vector<int> ssum;
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    ssum.push_back(0);
    for (int i = 2; i < sqrt(4000000); i++)
    {
        for (int j = i + i; j <= 4000000; j += i)
        {
            table[j] = 1;
        }
    }

    for (int i = 2; i <= 4000000; i++)
    {
        if (table[i] == 0)
        {
            sum += i;
            ssum.push_back(sum);
        }
    }

    int ans = 0, l = 0, r = 0;

    while (l <= r && r < ssum.size())
    {
        if (ssum[r] - ssum[l] > n)
            l++;
        else if (ssum[r] - ssum[l] < n)
            r++;
        else
        {
            ans++;
            r++;
        }
    }
    cout << ans;
}
