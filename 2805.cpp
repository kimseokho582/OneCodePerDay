#include <iostream>
#include <algorithm>

using namespace std;

long long table[1000001];
int n, m;

bool calc(long long x)
{
    long long rtn = 0;
    for (int i = 0; i < n; i++)
    {
        if (table[i] >= x)
        {
            rtn += (table[i] - x);
        }
        if (rtn >= m)
            return true;
    }
    return false;
}

int main()
{

    long long left = 0, right = 0;
    long long mid, answer;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
        right = max(right, table[i]);
    }

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (calc(mid))
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << answer;
}