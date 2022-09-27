#include <iostream>

using namespace std;

int table[1000001];
int lis[1000001];

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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    lis[0] = table[0];
    int tableIdx = 1;
    int lisIdx = 0;

    while (tableIdx < n)
    {
        if (lis[lisIdx] < table[tableIdx])
        {
            lis[++lisIdx] = table[tableIdx];
        }
        else
        {
            int idx = calc(0, lisIdx, table[tableIdx]);
            lis[idx] = table[tableIdx];
        }
        tableIdx++;
    }
    cout << lisIdx + 1;
}