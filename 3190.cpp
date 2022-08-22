#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int N, K, L;
deque<pair<int, int>> dq;
vector<int> vtime;
vector<char> vdir;
int map[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dummy(int sx, int sy)
{
    int dir = 0;
    int cnt = 0;
    int x, y;
    int idx = 0;
    dq.push_back({sx, sy});
    while (1)
    {
        x = dq.front().first;
        y = dq.front().second;
        map[y][x] = 2;
        cnt++;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[ny][nx] == 2)
        {
            return cnt;
        }
        else
        {
            dq.push_front({nx, ny});

            if (map[ny][nx] != 1)
            {
                int xend, yend;
                xend = dq.back().first;
                yend = dq.back().second;
                map[yend][xend] = 0;
                dq.pop_back();
            }

            if (cnt == vtime[idx])
            {
                if (vdir[idx] == 'L')
                {
                    dir += 3;
                    dir %= 4;
                }
                else
                {
                    dir += 1;
                    dir %= 4;
                }
                if (idx < vtime.size() - 1)
                {
                    idx++;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int applex, appley;
        cin >> applex >> appley;
        map[applex - 1][appley - 1] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int t;
        char d;
        cin >> t >> d;
        vtime.push_back(t);
        vdir.push_back(d);
    }
    cout << dummy(0, 0);
    return 0;
}
