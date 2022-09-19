#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> p)
{

    sort(p.begin(), p.end());
    for (int i = 0; i < p.size() - 1; i++)
    {
        int now = p[i].length();
        int next = p[i + 1].length();
        if (now > next)
            continue;
        if (p[i + 1].substr(0, now) == p[i])
        {
            return false;
        }
    }
    return true;
}