#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> L; //오름차순
priority_queue<int> S;                            //내림차순
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        !(i % 2) ? S.push(tmp) : L.push(tmp);

        if (!S.empty() && !L.empty())
        {
            while (S.top() > L.top())
            {
                L.push(S.top());
                S.pop();
                S.push(L.top());
                L.pop();
            }
        }

        if (!S.empty())
            cout << S.top() << "\n";
    }
}