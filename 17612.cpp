#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Custom
{
public:
    int CustomerN;
    int Time;
    int CounterN;
};

struct cmp
{
    bool operator()(Custom a, Custom b)
    {
        if (a.Time == b.Time)
        {
            if (a.CounterN > b.CounterN)
            {
                return true;
            }
            return false;
        }
        else
        {
            if (a.Time > b.Time)
            {
                return true;
            }
            return false;
        }
    }
};

bool Cmp(Custom a, Custom b)
{
    if (a.Time == b.Time)
    {
        if (a.CounterN > b.CounterN)
        {
            return true;
        }
        return false;
    }
    else
    {
        if (a.Time < b.Time)
        {
            return true;
        }
        return false;
    }
}

int n, k;
vector<pair<int, int>> customer;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        customer.push_back({a, b});
    }

    priority_queue<Custom, vector<Custom>, cmp> q;
    vector<Custom> exit;
    bool flag = false;
    for (int i = 0; i < k; i++)
    {
        if (i == n)
        {
            flag = true;
            break;
        }
        int custom_num = customer[i].first;
        int custom_time = customer[i].second;
        q.push({custom_num, custom_time, i + 1});
    }

    if (flag == true)
    {
        while (q.empty() == 0)
        {
            exit.push_back(q.top());
            q.pop();
        }
    }
    else
    {
        for (int i = k; i < n; i++)
        {
            int custom_num = customer[i].first;
            int custom_time = customer[i].second;
            q.push({custom_num, custom_time + q.top().Time, q.top().CounterN});
            exit.push_back(q.top());
            q.pop();
        }
        while (q.empty() == 0)
        {
            exit.push_back(q.top());
            q.pop();
        }
    }
    sort(exit.begin(), exit.end(), Cmp);
    long long ans = 0;
    for (int i = 0; i < exit.size(); i++)
    {
        int num = exit[i].CustomerN;
        long long rst = (long long)((i + 1) * (long long)num);
        ans += rst;
    }
    cout << ans;
}