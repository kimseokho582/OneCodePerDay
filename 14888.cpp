#include <iostream>
#include <algorithm>
using namespace std;

int number[12];
int operators[5];
int n;
int small = 999999999;
int large = -999999999;
void calc(int num, int idx)
{
    if (n == idx)
    {
        small = min(small, num);
        large = max(large, num);
    }

    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
        {
            operators[i]--;
            if (i == 0)
            {
                calc(num + number[idx], idx + 1);
            }
            else if (i == 1)
            {
                calc(num - number[idx], idx + 1);
            }
            else if (i == 2)
            {
                calc(num * number[idx], idx + 1);
            }
            else
            {
                calc(num / number[idx], idx + 1);
            }
            operators[i]++;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> operators[i];
    }

    calc(number[0], 1);
    cout << large << "\n"
         << small;
}
