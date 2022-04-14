#include <iostream>
#include <stack>
using namespace std;

bool check(string str)
{
    stack<int> stack;

    for (int j = 0; j < str.length(); j++)
    {
        if (str[j] == '(')
            stack.push(str[j]);
        else if (str[j] == ')')
        {
            if (!stack.empty())
                stack.pop();
            else
                return false;
        }
    }
    if (stack.empty())
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        cout << (check(str) ? "YES" : "NO") << endl;
    }
}