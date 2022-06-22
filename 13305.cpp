#include <iostream>
#include <algorithm>

using namespace std;

long long length[100001] = {
    0,
};

int main()
{
    int n;
    long long now = 1000000001, ans = 0;
    cin >> n;
    for (int i = 0; i < (n - 1); i++)
    {
        cin >> length[i];
    }

    for (int i = 0; i < n; i++)
    {
        long long oil;
        cin >> oil;
        now = min(oil, now);
        ans += (length[i] * now);
    }
    cout << ans;
}