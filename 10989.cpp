#include <iostream>

using namespace std;
int table[10001] = {
    0,
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        table[tmp]++;
    }

    for (int i = 0; i < 10001; i++)
    {
        for (int j = 0; j < table[i]; j++)
        {
            cout << i << "\n";
        }
    }
}