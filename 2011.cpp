#include <iostream>

using namespace std;

long long dp[5001];
int main()
{
    string str;
    cin >> str;
    str = " " + str;
    dp[0] = 1;
    for (int i = 1; i < str.size(); i++)
    {
        int x = str[i] - '0';
        if (0 < x)
        {
            dp[i] = dp[i - 1] % 1000000;
        }
        if (i == 1 || str[i - 1] == '0')
            continue;
        x = (str[i - 1] - '0') * 10 + (str[i] - '0');
        if (10 <= x && x <= 26)
            dp[i] = (dp[i] + dp[i - 2]) % 1000000;
    }
    cout << dp[str.size() - 1] << endl;
}