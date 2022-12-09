#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v;
int table[8001] = {
    0,
};
int main()
{
    int sum = 0;
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        sum += tmp;
        v.push_back(tmp);
        table[tmp + 4000]++;
    }
    sort(v.begin(), v.end());

    int most = -9999;
    bool isNotFirst = false;
    int ans;
    for (int i = 0; i < 8001; i++)
    {
        if (table[i] == 0)
            continue;
        if (table[i] == most)
        {
            if (isNotFirst)
            {
                ans = i - 4000;
                isNotFirst = false;
            }
        }
        if (table[i] > most)
        {
            most = table[i];
            ans = i - 4000;
            isNotFirst = true;
        }
    }
    int ans1 = round((double)sum / n);
    cout << ans1 << endl
         << v[v.size() / 2] << endl
         << ans << endl
         << v.back() - v.front();
}
