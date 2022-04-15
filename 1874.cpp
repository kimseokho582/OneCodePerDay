#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> v;
vector<char> ans;
stack<int> s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int idx = 0;
    for (int i = 1; i <= n; i++)
    {
        s.push(i);
        ans.push_back('+');

        while (!s.empty() && v[idx] == s.top())
        {
            ans.push_back('-');
            s.pop();
            idx++;
        }
        if (!s.empty() && v[idx] < s.top())
        {
            cout << "NO";
            exit(0);
        }
    }
    for (char x : ans)
        cout << x << "\n";
}