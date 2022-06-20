#include <iostream>
using namespace std;

int heap[100001];
int cnt = 0;

int pop()
{
    int first, parent, child, tmp;
    first = heap[1];
    parent = 1;
    child = 2;
    tmp = heap[cnt--];
    while (child <= cnt)
    {
        if ((child < cnt) && (heap[child] > heap[child + 1]))
            child++;

        if (heap[child] >= tmp)
            break;

        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = tmp;
    return first;
}

void push(int x)
{
    int i = ++cnt;
    while ((i != 0) && x < heap[i / 2])
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        push(tmp);
    }

    while (cnt > 1)
    {
        int anstmp = 0;
        for (int i = 0; i < 2; i++)
        {
            anstmp += pop();
        }
        push(anstmp);

        ans += anstmp;
    }
    cout << ans;
}