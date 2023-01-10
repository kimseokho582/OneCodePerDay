#include <iostream>

using namespace std;

int table[51][51];

int n, m;

void calc(int term)
{

    for (int i = 0; i < n - term; i++)
    {
        for (int j = 0; j < m - term; j++)
        {
            if (table[i][j] == table[i + term][j] && table[i][j] == table[i][j + term] && table[i][j] == table[i + term][j + term])
            {

                cout << (term + 1) * (term + 1);
                exit(0);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            table[i][j] = str[j] - '0';
        }
    }
    for (int i = (n > m ? m : n) - 1; i >= 1; i--)
    {
        calc(i);
    }
    cout << 1;
}