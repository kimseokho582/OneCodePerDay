#include <iostream>
#include <vector>
using namespace std;

int table[10001][10001];

vector<pair<int, int>> v;

int main()
{
    int n, m;
    int qx, qy;
    cin >> n >> m >> qy >> qx;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    int ans = 0, r = n + 1, l = 0, u = n + 1, d = 0, ru = n + 1, rd = 0, lu = n + 1, ld = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i].second;
        int y = v[i].first;
        if (y == qy)
        {
            if (x > qx)
                r = min(r, x);
            else
                l = max(l, x);
        }
        else if (x == qx)
        {
            if (y > qy)
                u = min(u, y);
            else
                d = max(d, y);
        }
        else if (x + y == qx + qy)
        {
            if (y > qy)
            {
                lu = min(lu, y);
            }
            else
            {
                rd = max(rd, y);
            }
        }
        else if (y - x == qy - qx)
        {
            if (y > qy)
            {
                ru = min(ru, y);
            }
            else
            {
                ld = max(ld, y);
            }
        }
    }

    ans += (r - qx - 1);
    ans += (qx - l - 1);
    ans += (u - qy - 1);
    ans += (qy - d - 1);
    ans += min(qx - 1, lu - qy - 1);
    ans += min(qx - 1, qy - ld - 1);
    ans += min(n - qx, qy - rd - 1);
    ans += min(n - qx, ru - qy - 1);
    cout << ans;
}
