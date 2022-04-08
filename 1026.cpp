#include <iostream>
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
    int n, ans = 0;
    cin >> n;
    int A[51], B[51], idx[51] = {
                          0,
                      };
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A, A + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (B[i] < B[j])
            {
                idx[j]++;
            }
            else if (B[i] == B[j])
            {
                if (i < j)
                    idx[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == idx[j])
            {
                ans += A[i] * B[j];
            }
        }
    }
    cout << ans;
}