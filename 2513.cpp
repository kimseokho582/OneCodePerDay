#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int caculateDistance(vector<pair<int, int>> &Students, int k, int s)
{
    int nowPos, nowNum, ans;

    nowPos = s;
    nowNum = 0;
    ans = 0;

    while (!Students.empty())
    {
        int pos = Students.back().first;
        int num = Students.back().second;

        if (num + nowNum <= k)
        {
            Students.pop_back();
            nowNum += num;
        }
        else
        {
            Students.back().second -= k - nowNum;
            nowNum += k - nowNum;
        }

        ans += abs(nowPos - pos);
        nowPos = pos;

        if (nowNum == k || Students.empty())
        {
            ans += abs(nowPos - s);
            nowPos = s;
            nowNum = 0;
        }
    }

    return ans;
}

int main()
{

    int n, k, s;
    cin >> n >> k >> s;

    vector<pair<int, int>> leftStudents, rightStudents;

    for (int i = 0; i < n; i++)
    {
        int pos, num;
        cin >> pos >> num;
        if (pos < s)
        {
            leftStudents.push_back(make_pair(pos, num));
        }
        else if (pos > s)
        {
            rightStudents.push_back(make_pair(pos, num));
        }
    }

    sort(leftStudents.begin(), leftStudents.end(), greater<>());
    sort(rightStudents.begin(), rightStudents.end(), less<>());

    cout << caculateDistance(leftStudents, k, s) + caculateDistance(rightStudents, k, s);

    return 0;
}