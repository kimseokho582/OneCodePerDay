#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long min, max;
    cin >> min >> max;
    vector<bool> table(max - min + 1, false);
    long long idx = 2;
    long long cnt = max - min + 1;
    while (idx * idx <= max)
    {
        long long pownum = idx * idx;
        long long num = min / pownum;
        if (num * pownum < min)
            num++;

        while (num * pownum <= max)
        {
            if (table[num * pownum - min] == 0)
            {
                table[num * pownum - min] = 1;
                cnt--;
            }
            num++;
        }
        idx++;
    }
    cout << cnt;
}