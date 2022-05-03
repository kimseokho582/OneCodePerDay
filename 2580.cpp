#include <iostream>
#include <vector>

using namespace std;

int table[10][10];
vector<pair<int, int> > zero;
int cnt = 0;
bool done = false;

bool check(pair<int, int> a)
{
    int x = a.first / 3;
    int y = a.second / 3;
    for (int i = 0; i < 9; i++)
    {
        if (table[a.first][i] == table[a.first][a.second] && i != a.second)
            return false;

        if (table[i][a.second] == table[a.first][a.second] && i != a.first)
            return false;
    }

    for (int i = 3 * x; i < 3 * x + 3; i++)
    {
        for (int j = 3 * y; j < 3 * y + 3; j++)
        {
            if (table[i][j] == table[a.first][a.second])
            {
                if (i != a.first && j != a.second)
                    return false;
            }
        }
    }
    return true;
}

void calc(int n)
{
    if (cnt == n)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
        done = true;
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        table[zero[n].first][zero[n].second] = i;
        if (check(zero[n]))
        {
            calc(n + 1);
        }
        if (done)
            return;
    }
    table[zero[n].first][zero[n].second] = 0;
    return;
}

int main()
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> table[i][j];
            if (table[i][j] == 0)
            {
                cnt++;
                zero.push_back({i, j});
            }
        }
    }

    calc(0);
}
