#include <iostream>
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
        int idx = -1;
        int flag = 0;
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
                if (idx == -1)
                    idx = i;
                if (mainStr[i] - cmpStr[i] > 1 || mainStr[i] - cmpStr[i] < -1)
                    flag = 1;
                else
                {
                    diff++;
                    if (diff == 2)
                    {
                        if ((mainStr[idx] + mainStr[i]) != (cmpStr[idx] + cmpStr[i]))
                            flag = 1;
                    }
                    if (diff >= 3)
                        flag = 1;
                }
            }
        }
        if (flag == 0)
            ans++;
        memset(cmpStr, 0, sizeof(cmpStr));
    }
    cout << ans;
}