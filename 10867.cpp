#include <iostream>
#include <set>
using namespace std;

set<int> s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        s.insert(num);
    }
    for (auto x : s)
    {
        cout << x << " ";
    }
}