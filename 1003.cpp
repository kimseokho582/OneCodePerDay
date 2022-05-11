#include <iostream>
using namespace std;

int cnt0, cnt1;
int table[41] = {
    0,
    1,
};
int fibonacci(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    if (table[n] != 0)
        return table[n];
    else
        return table[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            cout << "1 0"
                 << "\n";
        }
        else
        {
            fibonacci(num);
            cout << table[num - 1] << " " << table[num] << "\n";
        }
    }
}