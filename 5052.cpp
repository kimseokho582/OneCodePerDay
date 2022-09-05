#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int flag = 0;
        int n;
        int now;
        int next;
        vector<string> v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < n - 1; i++)
        {
            now = v[i].length();
            next = v[i + 1].length();
            if (now >= next)
                continue;

            if (v[i + 1].substr(0, now) == v[i])
            {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "YES" << endl;
    }
}