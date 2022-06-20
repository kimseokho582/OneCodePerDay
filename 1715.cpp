#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    while (pq.size() > 1)
    {
        int anstmp = 0;
        for (int i = 0; i < 2; i++)
        {
            anstmp += pq.top();
            pq.pop();
        }
        ans += anstmp;
        pq.push(anstmp);
    }
    cout << ans;
}