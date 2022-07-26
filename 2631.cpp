#include <iostream>
#include <algorithm>
using namespace std;

int table[201];
int LIS[201];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    int large = 0;
    for (int i = 0; i < n; i++)
    {
        LIS[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (table[i] > table[j] && LIS[i] < LIS[j] + 1)
            {
                LIS[i]++;
            }
        }
        large = max(large, LIS[i]);
    }
    cout << n - large << endl;
}