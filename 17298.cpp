#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
stack<int> s;
int ans[1000001];
int table[1000001];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> table[i];

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= table[i])
            s.pop();

        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();

        s.push(table[i]);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}