#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt = 0;
    cin >> n;
    while (!(n % 5 == 0 || n <= 0))
    {
        n -= 2;
        cnt++;
    }
    if (n < 0)
    {
        cout << "-1";
        return 0;
    }
    cout << n / 5 + cnt;
}