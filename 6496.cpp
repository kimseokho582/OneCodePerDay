#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct ks
{
    int from;
    int to;
    int val;
} KS;

bool cmp(KS a, KS b)
{
    return a.val < b.val;
}
vector<ks> v;
int n, m;

int parent[200010];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{

    int xx = find(x);
    int yy = find(y);

    parent[xx] = yy;
}

int main()
{
    while (1)
    {
        int cost = 0;
        int rst = 0;
        v.clear();
        for (int i = 0; i < 200010; i++)
        {
            parent[i] = i;
        }
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }

        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            cost += c;
            KS tmp = {a, b, c};
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < m; i++)
        {
            int x = find(v[i].from);
            int y = find(v[i].to);
            if (x != y)
            {
                merge(x, y);
                rst += v[i].val;
            }
        }
        cout << cost - rst << "\n";
    }
}
