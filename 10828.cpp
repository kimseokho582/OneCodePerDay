#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int ptr = -1;
    int stk[10001];
    string order = "";
    while (n--)
    {
        cin >> order;
        if (order[0] == 'p')
        {
            if (order[1] == 'u')
            { // push
                int num;
                cin >> num;
                stk[++ptr] = num;
            }
            else
            { // pop
                if (ptr == -1)
                    cout << -1 << "\n";
                else
                {
                    cout << stk[ptr--] << "\n";
                }
            }
        }
        else if (order[0] == 's')
        { // size
            cout << ptr + 1 << "\n";
        }
        else if (order[0] == 'e')
        { // empty
            ptr == -1 ? cout << 1 : cout << 0;
            cout << "\n";
        }
        else if (order[0] == 't')
        { // top
            if (ptr == -1)
                cout << -1 << "\n";
            else
            {
                cout << stk[ptr] << "\n";
            }
        }
    }
}