#include <iostream>
using namespace std;

int lotto[7];
int table[14];
int n;
void calc(int lidx, int tidx)
{
    if (lidx == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << lotto[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = tidx; i < n; i++)
    {
        lotto[lidx] = table[i];
        calc(lidx + 1, i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> table[i];
        }
        calc(0, 0);
        cout << "\n";
    }
}