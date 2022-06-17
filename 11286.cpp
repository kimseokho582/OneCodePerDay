#include <iostream>
#include <cmath>

using namespace std;
int heap[100001];
int cnt = 0;
void push(int x)
{
    int i = ++cnt;
    while ((i != 0) && abs(x) <= abs(heap[i / 2]))
    {

        if (abs(x) == abs(heap[i / 2]) && x > heap[i / 2])
            break;

        heap[i] = heap[i / 2];
        i = i / 2;
    }
    heap[i] = x;
}

int pop()
{
    int first, tmp, parent, child;
    first = heap[1];
    tmp = heap[cnt--];
    parent = 1;
    child = 2;

    while (child <= cnt)
    {
        if (((child < cnt) && abs(heap[child]) > abs(heap[child + 1])) || ((child < cnt) && abs(heap[child]) == abs(heap[child + 1]) && heap[child] > heap[child + 1]))
            child++;

        if (abs(tmp) < abs(heap[child]) || (abs(tmp) == abs(heap[child]) && (tmp < heap[child])))
            break;

        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = tmp;
    return first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp != 0)
        {
            push(tmp);
        }
        else
        {
            if (cnt == 0)
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << pop() << "\n";
            }
        }
    }
}