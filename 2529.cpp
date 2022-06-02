#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char str[12];
int check[10] = {
    0,
};
int n;
bool done = false;

void getsmall(string num, int cnt, int pre)
{
    if (done)
        return;

    if (cnt == n + 1)
    {
        cout << num << endl;
        done = true;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (cnt == 0 || (str[cnt] == '<' && pre < i && check[i] != 1) || (str[cnt] != '<' && pre > i && check[i] != 1))
        {
            num += i + '0';
            check[i] = 1;

            getsmall(num, cnt + 1, i);

            check[i] = 0;
            num.pop_back();
        }
    }
}

void getlarge(string num, int cnt, int pre)
{
    if (done)
        return;

    if (cnt == n + 1)
    {
        cout << num << endl;
        done = true;
    }

    for (int i = 9; i >= 0; i--)
    {
        if (cnt == 0 || (str[cnt] == '<' && pre < i && check[i] != 1) || (str[cnt] != '<' && pre > i && check[i] != 1))
        {
            num += i + '0';
            check[i] = 1;
            getlarge(num, cnt + 1, i);
            check[i] = 0;
            num.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> str[i];
    }
    getlarge("", 0, 9);
    check[9] = {
        0,
    };
    done = false;
    getsmall("", 0, 0);
}