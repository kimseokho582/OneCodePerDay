#include <iostream>

using namespace std;
int table[1001];
int main()
{
    int n;
    cin >> n;
    table[1] = 1;
    table[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        table[i] = (table[i - 1] + table[i - 2] * 2) % 10007;
    }
    cout << table[n];
}