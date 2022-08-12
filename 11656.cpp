#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> sv;

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        sv.push_back(str.substr(i, str.length()));
    }
    sort(sv.begin(), sv.end());
    for (int i = 0; i < sv.size(); i++)
    {
        cout << sv[i] << "\n";
    }
}