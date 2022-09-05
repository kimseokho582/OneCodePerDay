#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    stack<pair<int, int>> s;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        while (!s.empty())
        {
            if (s.top().first > x)
            {
                cout << s.top().second << " ";
                break;
            }
            s.pop();
        }
        if (s.empty())
        {
            cout << 0 << " ";
        }
        s.push({x, i});
    }
}