#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
int n, m, ans = 0;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }

    while (m--)
    {
        int num;
        cin >> num;
        int left, right;
        for (int i = 0; i < dq.size(); i++)
        {
            if (dq[i] == num)
            {
                left = i;
                right = dq.size() - i;
                break;
            }
        }
        if (left <= right)
        {
            while (1)
            {
                if (dq.front() == num)
                    break;
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
            dq.pop_front();
        }
        else
        {
            ans++;
            while (1)
            {
                if (dq.back() == num)
                    break;
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
            dq.pop_back();
        }
    }
    cout << ans;
}