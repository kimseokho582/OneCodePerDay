#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, k;
vector<pair<int, int>> v;

bool calc(int fuel)
{
    bool visited[1010] = {
        0,
    };
    int cnt = 0;
    queue<int> q;
    int qsize = 0, now;
    q.push(0);

    while (!q.empty())
    {
        if (cnt > k)
        {

            return false;
        }
        qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            now = q.front();
            q.pop();
            if (!visited[now])
            {
                visited[now] = true;

                for (int j = 1; j <= n; j++)
                {
                    double dis = sqrt(pow(v[now].first - v[j].first, 2) + pow(v[now].second - v[j].second, 2));
                    if (dis <= fuel)
                    {
                        double rest = sqrt(pow(10000 - v[j].first, 2) + pow(10000 - v[j].second, 2));
                        if (rest <= fuel)
                        {

                            return true;
                        }
                        q.push(j);
                    }
                }
            }
        }
        cnt++;
    }
    return false;
}

int main()
{
    cin >> n >> k;
    v.push_back({0, 0});
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    int l = 0;
    int r = 2000;
    int m, ans;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (calc(m * 10))
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans;
}