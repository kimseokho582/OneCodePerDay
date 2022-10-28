#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

int calc(int left, int right, int cnt, string str)
{
    while (left < right)
    {
        if (str[left] != str[right])
        {
            if (cnt == 0)
            {
                if (calc(left + 1, right, 1, str) == 0 || calc(left, right - 1, 1, str) == 0)
                    return 1;
                return 2;
            }
            else
                return 2;
        }
        else
        {
            left++;
            right--;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int result = calc(0, str.length() - 1, 0, str);
        cout << result << endl;
    }
}