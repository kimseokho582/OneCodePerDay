#include <iostream>
#include <algorithm>
using namespace std;

long long n;
long long m;

long long calc(long long x)
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += min(x / i, n);
    }
    return sum;
}

int main()
{
    cin >> n >> m;
    m = min((long long)1000000000, m);

    long long low = 1;
    long long high = n * n;
    long long cnt;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        cnt = calc(mid);
        if (m <= cnt)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << low;
}