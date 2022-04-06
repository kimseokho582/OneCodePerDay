#include <iostream>
#include <string>
using namespace std;

int table[20001];
// push_f push_b pop_f pop_b size empty front back
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int f = 10000, b = 10000;
    while (n--)
    {
        string order;
        cin >> order;
        if (order == "push_front")
        {
            int num;
            cin >> num;
            table[f--] = num;
        }
        else if (order == "push_back")
        {
            int num;
            cin >> num;
            table[++b] = num;
        }
        else if (order == "pop_front")
        {
            cout << ((f == b) ? -1 : table[++f]);
            cout << "\n";
        }
        else if (order == "pop_back")
        {
            cout << ((f == b) ? -1 : table[b--]);
            cout << "\n";
        }
        else if (order == "size")
        {
            cout << b - f << "\n";
        }
        else if (order == "empty")
        {
            cout << ((f == b) ? 1 : 0);
            cout << "\n";
        }
        else if (order == "front")
        {
            cout << ((f == b) ? -1 : table[f + 1]);
            cout << "\n";
        }
        else if (order == "back")
        {
            cout << ((f == b) ? -1 : table[b]);
            cout << "\n";
        }
    }
}