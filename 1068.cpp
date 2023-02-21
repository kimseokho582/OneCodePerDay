#include <iostream>
#include <vector>
using namespace std;

vector<int> v[51];
int start;
int n, m;
int ans = 0;
int flag = 0;

void calc(int x)
{
    if (x == m)
    {
        if (flag == 1 && x != start)
        {
            ans++;
        }
        return;
    }
    if (v[x].empty())
    {

        ans++;
        return;
    }

    for (int i = 0; i < v[x].size(); i++)
    {
        if (v[x].size() == 1)
        {
            flag = 1;
        }
        calc(v[x][i]);
    }
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num != -1)
        {
            v[num].push_back(i);
        }
        else
        {
            start = i;
        }
    }
    cin >> m;
    calc(start);
    cout << ans;
}