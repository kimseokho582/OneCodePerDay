#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin >> str;
    int n;
    cin >> n;
    list<char> l(str.begin(), str.end());
    auto cursor = l.end();
    while (n--)
    {
        char order;
        cin >> order;
        if (order == 'L')
        {
            if (cursor != l.begin())
                cursor--;
        }
        else if (order == 'D')
        {
            if (cursor != l.end())
                cursor++;
        }
        else if (order == 'B')
        {
            if (cursor != l.begin())
            {
                l.erase((--cursor)++);
            }
        }
        else
        {
            char add;
            cin >> add;
            l.insert(cursor, add);
        }
    }
    for (auto i = l.begin(); i != l.end(); i++)
        cout << *i;
}