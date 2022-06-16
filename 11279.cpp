#include <iostream>

using namespace std;

int heap[100001];
int cnt = 0;

void push(int x)
{
    int i = ++cnt;
    while ((i != 1) && x > heap[i / 2]) //여기
    {
        heap[i] = heap[i / 2];
        i = i / 2;
    }
    heap[i] = x;
}

int pop()
{
    int first, temp, parent, child;
    first = heap[1];
    temp = heap[(cnt)--];
    parent = 1;
    child = 2;

    while (child <= cnt)
    {
        if ((child < cnt) && (heap[child] < heap[child + 1])) //두번째
            child++;

        if (temp >= heap[child]) //여기
            break;

        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }

    heap[parent] = temp;
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
        if (tmp == 0)
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
        else
        {
            push(tmp);
        }
    }
}