#include <iostream>
using namespace std;

int table[100001];
int n, m;
int r, l = 0;

bool calc(int x)
{
    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (table[i] > x)
        {
            return false;
        }

        if (sum + table[i] <= x)
        {
            sum += table[i];
        }
        else
        {

            sum = 0;
            i--;
            cnt++;
        }
    }

    if (sum != 0)
    {

        cnt++;
    }

    if (cnt <= m)
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
        r += table[i];
    }
    while (l <= r)
    {

        int mid = (l + r) / 2;

        if (calc(mid))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l;
}