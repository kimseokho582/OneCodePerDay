#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parseArr(string arr)
{
    vector<int> rtn;
    string tmp = "";
    for (int i = 0; i < arr.size(); i++)
    {
        if ('0' <= arr[i] && arr[i] <= '9')
        {
            tmp += arr[i];
        }
        else
        {
            if (tmp != "")
            {
                rtn.push_back(stoi(tmp));
                tmp = "";
            }
        }
    }
    return rtn;
}

string operatorArr(vector<int> v, string order)
{
    vector<int> tmp = v;
    string rtn = "[";
    bool rvs = 0;
    int f = 0, b = tmp.size() - 1;
    for (int i = 0; i < order.size(); i++)
    {
        if (order[i] == 'R')
        {
            rvs = !rvs;
        }
        else
        {
            if (f > b)
            {
                return "error";
            }

            rvs ? b-- : f++;
        }
    }
    if (rvs)
    {
        for (int i = b; i >= f; i--)
        {
            rtn += to_string(tmp[i]);
            if (i != f)
                rtn += ",";
        }
    }
    else
    {
        for (int i = f; i <= b; i++)
        {
            rtn += to_string(tmp[i]);
            if (i != b)
                rtn += ",";
        }
    }
    rtn += "]";
    return rtn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string order, arr;
        int n;
        vector<int> v;
        cin >> order >> n >> arr;
        v = parseArr(arr);
        cout << operatorArr(v, order) << "\n";
    }
}