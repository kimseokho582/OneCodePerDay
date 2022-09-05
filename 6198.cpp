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

    stack<int> s;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while (!s.empty())
        {
            if (s.top() > x)
            {
                break;
            }
            s.pop();
        }
        ans += (long long)s.size();
        s.push(x);
    }
    cout << ans;
}