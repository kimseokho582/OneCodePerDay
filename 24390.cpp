#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int dp[400];
int main()
{
    string str;
    cin >> str;
    int time = 0;
    time += (str[0] - '0') * 600;
    time += (str[1] - '0') * 60;
    time += (str[3] - '0') * 10;
    time += (str[4] - '0');
    if (time == 30)
    {
        cout << 1;
        return 0;
    }
    memset(dp, 9999, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[3] = 1;
    dp[6] = 1;
    dp[60] = 1;
    for (int i = 2; i <= (time / 10); i++)
    {

        dp[i] = min(dp[i], dp[i - 1] + 1);
        if (i >= 3)
        {
            dp[i] = min(dp[i], dp[i - 3] + 1);
        }
        if (i >= 6)
        {
            dp[i] = min(dp[i], dp[i - 6] + 1);
        }
        if (i >= 60)
        {
            dp[i] = min(dp[i], dp[i - 60] + 1);
        }
    }
    if (time > 30)
    {
        cout << min(dp[time / 10], dp[time / 10 - 3]) + 1;
    }
    else
    {
        cout << dp[time / 10] + 1;
    }
}