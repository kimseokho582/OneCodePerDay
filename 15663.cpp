#include <iostream>
#include <algorithm>

using namespace std;

int numbers[10];
int table[10];
int visited[10] = {
    0,
};
int n, m;

void calc(int num)
{
    if (num == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << numbers[table[i]] << " ";
        }
        cout << endl;
        return;
    }
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && tmp != numbers[i])
        {
            table[num] = i;
            tmp = numbers[i];
            visited[i] = 1;
            calc(num + 1);
            visited[i] = 0;
        }
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
    calc(0);
}