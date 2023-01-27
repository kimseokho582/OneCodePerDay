#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string str;
    stack<char> s;
    cin >> str;
    int operate = 0;
    int sum = 0;
    int tmp = 1;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[')
        {
            s.push(str[i]);
            str[i] == '(' ? tmp *= 2 : tmp *= 3;
        }
        else if (str[i] == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '(')
            {
                sum += tmp;
                tmp /= 2;
                s.pop();
            }
            else
            {
                tmp /= 2;
                s.pop();
            }
        }
        else if (str[i] == ']')
        {
            if (s.empty() || s.top() != '[')
            {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '[')
            {
                sum += tmp;
                tmp /= 3;
                s.pop();
            }
            else
            {
                tmp /= 3;
                s.pop();
            }
        }
    }
    if (!s.empty())
        sum = 0;
    cout << sum;
}