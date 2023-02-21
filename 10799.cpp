#include <iostream>
#include <stack>
using namespace std;

stack<char> s;
int main()
{
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')' && str[i - 1] == '(')
        {
            s.pop();
            ans += s.size();
        }
        else
        {
            ans++;
            s.pop();
        }
    }
    cout << ans;
}