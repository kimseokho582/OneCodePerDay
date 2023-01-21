#include <iostream>
#include <vector>
using namespace std;

bool visited[10];
bool flag;
vector<int> v;
int table[10];

void dfs(int idx, int cnt, int sum)
{
    if (sum > 100)
        return;
    if (cnt == 7 && sum == 100)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << table[v[i]] << endl;
        }
        exit(0);
    }
    for (int i = idx; i < 9; i++)
    {
        if (visited[i] == true)
            continue;
        visited[i] = true;
        v.push_back(i);
        dfs(i, cnt + 1, sum + table[i]);
        v.pop_back();
        visited[i] = false;
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
        cin >> table[i];
    dfs(0, 0, 0);
}