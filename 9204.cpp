#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char tmp[5];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int x1, x2, y1, y2;

        for (int i = 0; i < 4; i++)
        {
            cin >> tmp[i];
        }
        x1 = tmp[0] - '@';
        y1 = tmp[1] - '0';
        x2 = tmp[2] - '@';
        y2 = tmp[3] - '0';

        if ((x1 % 2 == y1 % 2) != (x2 % 2 == y2 % 2))
        {
            cout << "Impossible"
                 << "\n";
            continue;
        }
        else if (x1 == x2 && y1 == y2)
        {
            cout << 0 << " " << (char)(x1 + '@') << " " << y1 << "\n";
        }
        else if (((x1 + y1) == (x2 + y2)) || ((y1 - x1) == (y2 - x2)))
        {
            cout << 1 << " " << (char)(x1 + '@') << " " << y1 << (char)(x2 + '@') << " " << y2 << "\n";
        }
        else
        {
            cout << 2 << " " << (char)(x1 + '@') << " " << y1 << " ";

            if ((x1 + y1 + y2 - x2) > 0 && (x1 + y1 + x2 - y2) > 0)
            {
                cout << (char)(((x1 + y1 + x2 - y2) / 2) + '@') << " " << (x1 + y1 - x2 + y2) / 2 << " ";
            }
            else
            {
                cout << (char)(((y2 + x2 - y1 + x1) / 2) + '@') << " " << (y2 + x2 + y1 - x1) / 2 << " ";
            }

            cout << (char)(x2 + '@') << " " << y2 << "\n";
        }
    }
}