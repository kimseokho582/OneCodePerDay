#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int x, int y)
{
    return x > y;
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
        int n, m, cnt = 0;
        cin >> n >> m;
        queue<int> q;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            q.push(num);
            v.push_back(num);
        }
        sort(v.begin(), v.end(), cmp);
        while (1)
        {
            if (v[cnt] == q.front())
            {
                if (m == 0)
                {
                    cout << cnt + 1
                         << "\n";
                    break;
                }
                else
                {
                    cnt++;
                }
            }
            q.push(q.front());
            q.pop();
            m--;
            if (m < 0)
                m = q.size() - 1;
        }
    }
}