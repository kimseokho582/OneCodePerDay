#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long l[5000];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> l[i];
    }
    sort(l, l + N);

    long long x, a, n, s, sum;
    sum = 9999999999999;

    for (int i = 0; i < N - 2; i++)
    {
        x = l[i];
        int left = i + 1;
        int right = N - 1;
        while (left < right)
        {
            long long temp = x + l[left] + l[right];
            if (sum > abs(temp))
            {
                sum = abs(temp);
                a = x;
                n = l[left];
                s = l[right];
            }
            if (temp < 0)
                left++;
            else if (temp > 0)
                right--;
            else
            {
                i = N;
                break;
            }
        }
    }

    cout << a << " " << n << " " << s << endl;

    return 0;
}