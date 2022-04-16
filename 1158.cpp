#include <iostream>
using namespace std;

int table[5002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        table[i] = i + 1;
    }
    int idx = m - 1;
    cout << "<";
    while (1)
    {
        n--;
        cout << table[idx];
        if (n == 0)
            break;
        cout << ", ";
        for (int i = idx; i < n; i++)
            table[i] = table[i + 1];

        idx = (idx + m - 1) % n;
    }
    cout << ">";
}