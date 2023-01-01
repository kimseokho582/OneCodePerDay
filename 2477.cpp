#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<pair<int, int>> v;
    int bigx = 0, bigy = 0, smallx = 0, smally = 0;
    int n;
    cin >> n;
    for (int i = 0; i < 6; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1 || a == 2)
        {
            bigx = max(bigx, b);
        }

        if (a == 3 || a == 4)
        {
            bigy = max(bigy, b);
        }
        v.push_back({a, b});
    }
    for (int i = 0; i < 6; i++)
    {

        if (v[i].first == (v[(i + 2) % 6].first))
        {
            if (v[(i + 1) % 6].first == 1 || v[(i + 1) % 6].first == 2)
            {
                smallx = v[(i + 1) % 6].second;
            }

            if (v[(i + 1) % 6].first == 3 || v[(i + 1) % 6].first == 4)
            {
                smally = v[(i + 1) % 6].second;
            }
        }
    }

    cout << ((bigx * bigy) - (smallx * smally)) * n;
}