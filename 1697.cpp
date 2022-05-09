#include <iostream>
#include <queue>
#include <algorithm>
#define SIZE_MAX 1000001
using namespace std;
queue<pair<int, int> > table;
int check[SIZE_MAX] = {
    0,
};
int main()
{

    int N, K;
    cin >> N >> K;
    int point, time;
    check[N] == 1;
    table.push(make_pair(N, 0));
    while (!table.empty())
    {

        point = table.front().first;
        time = table.front().second;

        if (point == K)
        {
            cout << time;
            return 0;
        }

        table.pop();
        if (point + 1 < SIZE_MAX && check[point + 1] == 0)
        {
            table.push(make_pair(point + 1, time + 1));
            check[point + 1] = 1;
        }

        if (point - 1 >= 0 && check[point - 1] == 0)
        {
            table.push(make_pair(point - 1, time + 1));
            check[point - 1] = 1;
        }

        if (point * 2 < SIZE_MAX && check[point * 2] == 0)
        {
            table.push(make_pair(point * 2, time + 1));
            check[point * 2] = 1;
        }
    }
}