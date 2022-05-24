#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, num;
    cin >> n >> num;
    int ans = num;
    n--;
    while (n--)
    {
        int in;
        cin >> in;
        num = max(in, in + num);
        ans = max(ans, num);
    }
    cout << ans;
}