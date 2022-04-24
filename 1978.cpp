
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x)
{
    if (x == 1)
        return false;
    int a = sqrt(x);
    for (int i = 2; i <= a; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (isPrime(x))
            ans++;
    }
    cout << ans;
}

//에라토스테네스의 체로 푼 방법
// int table[1001];

// int main()
// {
//     for (int i = 2; i <= 1000; i++)
//     {
//         table[i] = i;
//     }
//     for (int i = 2; i <= 1000; i++)
//     {
//         if (!table[i])
//             continue;
//         for (int j = i + i; j <= 1000; j += i)
//         {

//             table[j] = 0;
//         }
//     }

//     int n;
//     cin >> n;
//     int ans = 0;
//     while (n--)
//     {
//         int x;
//         cin >> x;
//         if (table[x] != 0)
//             ans++;
//     }
//     cout << ans;
// }
