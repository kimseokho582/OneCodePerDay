#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sw1[10000] = {0};
    int sw2[10000] = {0};
    int line[10000] = {0};

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> sw1[i];
    for (int i = 0; i < n; i++)
        cin >> sw2[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (sw1[i] == sw2[j])
                line[i] = j;

    vector<int> vt;
    vector<int> record;
    vector<int> ret;
    int idx = 0;
    vt.push_back(line[0]);
    record.push_back(0);

    for (int i = 1; i < n; i++)
    {
        if (vt.back() < line[i])
        {
            vt.push_back(line[i]);
            record.push_back(++idx);
        }
        else
        {
            auto it = lower_bound(vt.begin(), vt.end(), line[i]);
            *it = line[i];
            record.push_back(it - vt.begin());
        }
    }

    int flag = idx;
    for (int i = n - 1; i >= 0; i--)
    {
        if (record[i] == flag)
        {
            ret.push_back(sw2[line[i]]);
            flag--;
        }
        if (flag == -1)
            break;
    }
    sort(ret.begin(), ret.end());

    cout << idx + 1 << "\n";
    for (auto it = ret.begin(); it != ret.end(); it++)
        cout << *it << " ";

    return 0;
}