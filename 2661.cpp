#include <iostream>
#include <string>
using namespace std;

string ans = "";
int n;

void calc(string str, int cnt)
{
    if (ans.length() == n)
        return;

    for (int i = 1; i <= cnt / 2; i++)
    {
        if (str.substr(cnt - i, i) == str.substr(cnt - 2 * i, i))
            return;
    }
    if (cnt == n)
    {
        ans = str;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        calc(str + "1", cnt + 1);
        calc(str + "2", cnt + 1);
        calc(str + "3", cnt + 1);
    }
}

int main()
{
    cin >> n;
    calc("", 0);
    cout << ans;
}