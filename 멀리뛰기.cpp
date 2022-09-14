#include <string>
#include <vector>

using namespace std;
long long table[2001];
long long solution(int n)
{

    table[1] = 1;
    table[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        table[i] = (table[i - 1] + table[i - 2]) % 1234567;
    }

    return table[n];
}