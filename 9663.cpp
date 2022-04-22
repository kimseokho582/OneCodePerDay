#include <iostream>
using namespace std;

int col[16];
int N, total = 0;

bool check(int level)
{
    for (int i = 0; i < level; i++)
        if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
            return false;
    return true;
}

void nqueen(int x)
{
    if (x == N)
    {

        total++;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            col[x] = i;
            if (check(x))
                nqueen(x + 1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    nqueen(0);
    cout << total;
}