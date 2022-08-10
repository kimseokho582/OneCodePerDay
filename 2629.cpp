#include <iostream>
#include <cmath>
using namespace std;

int n;
int table[31];
int dp[32][15002];

void clac(int idx, int w)
{

    if (dp[idx][w] == 1 || idx > n)
    {
        return;
    }
    dp[idx][w] = 1;
    clac(idx + 1, w + table[idx]);
    clac(idx + 1, w);
    clac(idx + 1, abs(w - table[idx]));
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    clac(0, 0);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int w;
        cin >> w;
        if (w > 15000)
            cout << "N"
                 << " ";
        else
        {
            if (dp[n][w] == 1)
            {
                cout << "Y"
                     << " ";
            }
            else
            {
                cout << "N"
                     << " ";
            }
        }
    }
}