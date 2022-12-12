#include <iostream>
#include <cmath>

int table[501][501];

using namespace std;

int main()
{
    int n, m, block;
    int ansheight, ans = 999999999;
    cin >> n >> m >> block;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
        }
    }

    for (int h = 0; h <= 256; h++)
    {
        int b = 0, r = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int height = table[i][j] - h;
                if (height > 0)
                    r += height;
                else if (height < 0)
                    b -= height;
            }
        }
        if (r + block >= b)
        {
            int time = r * 2 + b;
            if (ans >= time)
            {
                ans = time;
                ansheight = h;
            }
        }
    }
    cout << ans << " " << ansheight;
}