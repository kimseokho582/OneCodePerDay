#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int table[1001];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while (q.empty() == 0)
    {
        int Cur = q.front().first;
        int Cnt = q.front().second;
        q.pop();

        if (Cur == n - 1)
        {
            cout << Cnt << endl;
            break;
        }

        int S = table[Cur];
        for (int i = 1; i <= S; i++)
        {
            int Next = Cur + i;

            q.push(make_pair(Next, Cnt + 1));
        }
    }
    cout << -1 << endl;
}