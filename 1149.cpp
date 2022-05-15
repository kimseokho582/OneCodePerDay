#include <iostream>
#include <cmath>
using namespace std;

int table[3][1000];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int r, g, b;
        cin >> r >> g >> b;
        if (i == 0)
        {
            table[0][i] = r;
            table[1][i] = g;
            table[2][i] = b;
        }
        else
        {
            table[0][i] = min(table[1][i - 1], table[2][i - 1]) + r;
            table[1][i] = min(table[0][i - 1], table[2][i - 1]) + g;
            table[2][i] = min(table[0][i - 1], table[1][i - 1]) + b;
        }
    }
    cout << min(table[0][n - 1], min(table[1][n - 1], table[2][n - 1]));
}