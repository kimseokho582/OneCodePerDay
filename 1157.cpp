#include <iostream>
#include <cstring>

using namespace std;
int table[30];
int large = 0;
int second = 0;
int largeindex = 0;
int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 97)
        {
            table[str[i] - 97]++;
        }
        else
        {
            table[str[i] - 65]++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (table[i] >= large)
        {
            second = large;
            large = table[i];
            largeindex = i;
        }
    }
    if (large == second)
    {
        cout << "?";
    }
    else
    {
        cout << (char)(largeindex + 65);
    }
}