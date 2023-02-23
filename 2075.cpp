#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            if (q.size() < n)
            {
                q.push(num);
            }
            else
            {
                if (q.top() < num)
                {
                    q.pop();
                    q.push(num);
                }
            }
        }
    }
    cout << q.top();
}