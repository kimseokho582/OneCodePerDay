#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<double, double>> v;

double ccw(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double res = x1 * y2 + x2 * y3 + x3 * y1;
    res += (-y1 * x2 - y2 * x3 - y3 * x1);
    return res / 2;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    double ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += ccw(v[0].first, v[0].second, v[i - 1].first, v[i - 1].second, v[i].first, v[i].second);
    }
    printf("%.1lf", abs(ans));
}
