#include <iostream>

using namespace std;

int table[12];
int DP[12];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, large = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
        if (table[i] > large)
            large = table[i];
    }
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;

    for (int i = 4; i <= large; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
    }

    for (int i = 0; i < n; i++)
    {
        cout << DP[table[i]] << "\n";
    }
}