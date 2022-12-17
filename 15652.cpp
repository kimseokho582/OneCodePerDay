#include <iostream>

using namespace std;

int n, m;
int table[10];
void search(int num, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << table[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = num; i <= n; i++)
    {
        table[cnt] = i;
        search(i, cnt + 1);
    }
}

int main()
{
    cin >> n >> m;
    search(1, 0);
}