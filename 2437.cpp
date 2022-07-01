#include <iostream>
#include <algorithm>
using namespace std;

int table[1001];

int main()
{
    int n;
    cin >> n;
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    sort(table, table + n);
    for (int i = 0; i < n; i++)
    {
        if (num < table[i])
            break;

        num += table[i];
    }
    cout << num;
}