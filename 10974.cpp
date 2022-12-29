#include <iostream>

using namespace std;

int table[10];
int visited[10] = {
    0,
};
int n;
void calc(int num)
{
    if (num == n)
    {
        for (int i = 0; i < num; i++)
        {
            cout << table[i] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        visited[i] = 1;
        table[num] = i;
        calc(num + 1);
        visited[i] = 0;
    }
}

int main()
{
    cin >> n;

    calc(0);
}