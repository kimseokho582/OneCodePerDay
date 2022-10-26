#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[4001][4001] = {
    0,
};

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int ans = 0;
    for (int i = 1; i <= str1.length(); i++)
    {
        for (int j = 1; j <= str2.length(); j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
            ans = max(dp[i][j], ans);
        }
    }

    cout << ans;
}