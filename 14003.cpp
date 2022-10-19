#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int table[1000001];
int lis[1000001];
int IdxList[1000001];

int calc(int l, int r, int num)
{
    int mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (lis[mid] < num)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return r;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    int tableIdx = 1;
    int lisIdx = 0;
    lis[0] = table[0];

    while (tableIdx < n)
    {
        if (lis[lisIdx] < table[tableIdx])
        {
            lis[++lisIdx] = table[tableIdx];
            IdxList[tableIdx] = lisIdx;
        }
        else
        {
            int idx = calc(0, lisIdx, table[tableIdx]);
            lis[idx] = table[tableIdx];
            IdxList[tableIdx] = idx;
        }
        tableIdx++;
    }

    cout << lisIdx + 1 << "\n";

    for (int i = n - 1; i >= 0; i--)
    {
        if (IdxList[i] == lisIdx)
        {
            ans.push_back(table[i]);

            lisIdx--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}