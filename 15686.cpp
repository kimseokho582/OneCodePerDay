#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool divided[14];
vector<pair<int, int> > home;
vector<pair<int, int> > chicken;
int n, m, ans = 999999999;

void DFS(int cnt, int next)
{
    if (cnt == m)
    {
        int sum = 0;
        for (int i = 0; i < home.size(); i++)
        {
            int tmp = 999999999;
            for (int j = 0; j < chicken.size(); j++)
            {
                if (!divided[j])
                    continue;
                tmp = min(abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second), tmp);
            }
            sum += tmp;
        }
        ans = min(sum, ans);
    }
    for (int i = next; i < chicken.size(); i++)
    {
        divided[i] = true;
        DFS(cnt + 1, i + 1);
        divided[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            if (!tmp)
                continue;
            tmp == 1 ? home.push_back({i, j}) : chicken.push_back({i, j});
        }
    }
    DFS(0, 0);
    cout << ans;
}
