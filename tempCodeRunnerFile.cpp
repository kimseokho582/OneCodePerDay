#include <iostream>
#include <cmath>

using namespace std;

bool check(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b;
        cin >> a >> b;
        bool flag = 0;
        long long num = a + b;
        if (num <= 3)
        {
            cout << "NO"
                 << "\n";
        }
        else if ((num & 1) == 0)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            if (check(num - 2))
            {
                cout << "YES"
                     << "\n";
            }
            else
            {
                cout << "NO"
                     << "\n";
            }
        }
    }
}