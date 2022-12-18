#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int numbers[10];
int table[10];

void search(int num, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << numbers[table[i]] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = num; i < n; i++)
    {
        table[cnt] = i;
        search(i, cnt + 1);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    sort(numbers, numbers + n);
    search(0, 0);
}