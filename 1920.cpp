#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> A;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    //오름차순 정렬
    sort(A.begin(), A.end());

    cin >> M;
    int tmp;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        if (A[N - 1] >= tmp)
        {
            //현재 값이 lower_bound와 다르다면 = 값이 없다면 0,
            if (A[lower_bound(A.begin(), A.end(), tmp) - A.begin()] != tmp)
                cout << 0 << " ";
            //같다면 = 값이 있다면 1
            else
                cout << 1 << " ";
        }
        else
            cout << 0 << " ";
    }
}