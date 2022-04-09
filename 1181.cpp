#include <iostream>
#include <set>

using namespace std;

struct cmp
{
    bool operator()(const string &x, const string &y) const
    {
        if (x.size() == y.size())
        {
            return x < y;
        }
        else
        {
            return x.size() < y.size();
        }
    }
};

set<string, cmp> s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    for (auto str : s)
    {
        cout << str << endl;
    }
}