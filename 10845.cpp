#include <iostream>
#include <string>
using namespace std;
int table[10001];
// push pop size empty front back
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string order;
    int f = -1, b = -1;
    while (n--)
    {
        cin >> order;
        if (order[0] == 'p')
        {
            if (order[1] == 'u')
            {
                int num;
                cin >> num;
                table[++b] = num;
            }
            else
            {
                if (f == b)
                    cout << -1 << "\n";
                else
                {
                    cout << table[++f] << "\n";
                }
            }
        }
        else if (order[0] == 's')
        {
            cout << b - f << "\n";
        }
        else if (order[0] == 'e')
        {
            b == f ? cout << 1 : cout << 0;
            cout << "\n";
        }
        else if (order[0] == 'f')
        {
            b == f ? cout << -1 : cout << table[f + 1];
            cout << "\n";
        }
        else if (order[0] == 'b')
        {
            b == f ? cout << -1 : cout << table[b];
            ;
            cout << "\n";
        }
    }
}