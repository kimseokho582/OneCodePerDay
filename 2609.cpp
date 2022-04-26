#include <iostream>

using namespace std;

int calc(int x, int y)
{
    if (y == 0)
        return x;
    else
        return calc(y, x % y);
}

int main()
{
    int n, m;
    cin >> n >> m;
    int num = calc(n, m);
    cout << num << "\n"
         << n * m / num;
}