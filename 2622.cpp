#include <iostream>

using namespace std;
int n, cnt;

int main()
{
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int c = n - i - j;
            if (j > c)
                break;
            if (i + j > c)
                cnt++;
        }
    }

    cout << cnt;
}