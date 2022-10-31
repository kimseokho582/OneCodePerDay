#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int mainStr[30];
int cmpStr[30] = {
    0,
};

int main()
{
    int ans = 0;
    int n;
    cin >> n;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        mainStr[str[i] - 65]++;
    }

    for (int i = 1; i < n; i++)
    {
        int diff = 0;
        string tmp;
        cin >> tmp;
        for (int i = 0; i < tmp.length(); i++)
        {
            cmpStr[tmp[i] - 65]++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (mainStr[i] != cmpStr[i])
            {
                diff++;
            }
        }

        memset(cmpStr, 0, sizeof(cmpStr));
        if (str.length() - tmp.length() > 2 || str.length() - tmp.length() < -2)
            continue;
        if (diff < 3)
            ans++;
    }
    cout << ans;
}