#include <string>
#include <vector>
using namespace std;
int table[100001];

int solution(int n)
{

    table[0] = 0;
    table[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        table[i] = (table[i - 1] + table[i - 2]) % 1234567;
    }

    return table[n];
}