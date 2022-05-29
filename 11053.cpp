#include <iostream>
#include <algorithm>
using namespace std;

class customPair
{
public:
    int num;
    int cnt = 1;
};

int main()
{
    customPair table[1001];

    int n, ans = 1;
    cin >> n;
    cin >> table[0].num;
    for (int i = 1; i < n; i++)
    {
        cin >> table[i].num;
        for (int j = 0; j < i; j++)
        {
            if (table[i].num > table[j].num && table[i].cnt <= table[j].cnt)
            {
                table[i].cnt++;
            }
        }
        ans = max(ans, table[i].cnt);
    }
    cout << ans;
}