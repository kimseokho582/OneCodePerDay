#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> m;
unordered_map<string, int> num;

string find(string a)
{
    if (m[a] == a)
    {
        return a;
    }
    else
    {
        return m[a] = find(m[a]);
    }
}

void calc(string a, string b)
{
    string x = find(a);
    string y = find(b);

    if (x == y)
        return;
    m[y] = x;
    num[x] += num[y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        m.clear();
        num.clear();

        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;
            if (m.count(a) == 0)
            {
                m.insert({a, a});
                num.insert({a, 1});
            }

            if (m.count(b) == 0)
            {
                m.insert({b, b});
                num.insert({b, 1});
            }

            calc(a, b);
            cout << num[find(a)] << "\n";
        }
    }
}