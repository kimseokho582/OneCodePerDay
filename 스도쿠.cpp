#include <iostream>
#include <cstring>
using namespace std;

bool r[9][9];
bool c[9][9];
bool s[9][9];
int table[9][9];

void dfs(int cnt)
{
    int x = cnt / 9;
    int y = cnt % 9;

    if (cnt == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << table[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }
    if (table[x][y] == 0)
    {

        for (int i = 1; i <= 9; i++)
        {
            if (r[x][i] == false && c[y][i] == false && s[(x / 3) * 3 + (y / 3)][i] == false)
            {

                r[x][i] = true;
                c[y][i] = true;
                s[(x / 3) * 3 + (y / 3)][i] = true;
                table[x][y] = i;
                dfs(cnt + 1);
                table[x][y] = 0;
                r[x][i] = false;
                c[y][i] = false;
                s[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
    else
    {
        dfs(cnt + 1);
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 9; j++)
        {
            table[i][j] = str[j] - '0';
            if (table[i][j] != 0)
            {
                r[i][table[i][j]] = true;
                c[j][table[i][j]] = true;
                s[(i / 3) * 3 + (j / 3)][table[i][j]] = true;
            }
        }
    }
    dfs(0);
}