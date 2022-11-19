#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    while (n > 0)
    {
        if (!(n % 5))
        {
            cout << n / 5 + ans;
            return 0;
        }
        ans++;
        n -= 2;
    }
    cout << -1;
}