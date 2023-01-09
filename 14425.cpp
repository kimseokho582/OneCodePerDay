#include <iostream>
#include <map>

using namespace std;
map<string, bool> table;
int main()
{
    int n, m;
    cin >> n >> m;
    string str;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        table.insert({str, true});
    }

    for (int i = 0; i < m; i++)
    {
        cin >> str;
        if (table[str] == true)
            ans++;
    }
    cout << ans;
}