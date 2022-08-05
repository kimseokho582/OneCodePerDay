#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int table[1001][1001] = {
    0,
};

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int ans = 0;
    for (int i = 1; i <= str1.length(); i++)
    {
        int tmp = 0;
        for (int j = 1; j <= str2.length(); j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                tmp = table[i][j];
            }
            else
            {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    string ansStr = "";
    for (int i = str1.length(); i > 0; i--)
    {
        for (int j = str2.length(); j > 0; j--)
        {
            if (table[i][j] == ans && table[i - 1][j] == (ans - 1) && table[i][j - 1] == (ans - 1) && table[i - 1][j - 1] == (ans - 1))
            {
                ans--;

                ansStr += str1[i - 1];
                break;
            }
        }
    }

    reverse(ansStr.begin(), ansStr.end());
    cout << ansStr;
}