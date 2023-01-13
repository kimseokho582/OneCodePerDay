#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main()
{
    int n;
    cin >> n;
    int num;
    while (1)
    {
        cin >> num;
        if (num == -1)
            break;
        if (num != 0 && q.size() < n)
        {
            q.push(num);
        }
        if (num == 0)
        {
            q.pop();
        }
    }

    if (q.empty())
    {
        cout << "empty";
    }
    else
    {
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }
}