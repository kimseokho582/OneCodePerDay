#include <iostream>
#include <cmath>

using namespace std;

bool check(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base ::sync_with_stdio(false);
    int num = 1;
    int x, y;
    bool flag = false;

    while (num)
    {
        cin >> num;
        for (int i = 1; i < num / 2; i++)
        {
            x = 2 * i + 1;
            y = num - x;
            if (check(x) && check(y))
            {
                cout << num << " = " << x << " + " << y << "\n";
                flag = true;
                break;
            }
        }
    }
    if (!flag)
        cout << "Goldbach's conjecture is wrong.";
}