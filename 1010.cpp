#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        long long ans = 1;
        int r = 1;
        for (int i = b; i > b - a; i--)
        {
            ans *= i;
            ans /= r++;
        }
        cout << ans << "\n";
    }
}