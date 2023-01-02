#include <iostream>
#include <cstring>
using namespace std;

int sum[200001][30];
string str;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (i != 0)
        {
            for (int j = 0; j < 26; j++)
            {
                sum[i][j] = sum[i - 1][j];
            }
        }
        int now = str[i] - 'a';
        sum[i][now]++;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char num;
        int l, r;
        cin >> num;
        cin >> l >> r;
        int now = num - 'a';

        int p1 = l > 0 ? sum[l - 1][now] : 0;
        int p2 = sum[r][now];
        cout << p2 - p1 << "\n";
    }
}