#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void qsort(string &arr, int l, int r, bool order)
{
    int left = l;
    int right = r;
    int pivot = arr[(l + r) / 2];
    int tmp;
    do
    {
        if (order)
        {
            while (arr[left] < pivot)
                left++;
            while (arr[right] > pivot)
                right--;
        }
        else
        {
            while (arr[left] > pivot)
                left++;
            while (arr[right] < pivot)
                right--;
        }

        if (left <= right)
        {
            tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }

    } while (left <= right);

    if (l < right)
        qsort(arr, l, right, order);

    if (left < r)
        qsort(arr, left, r, order);
}

int main()
{
    string str;
    cin >> str;

    qsort(str, 0, str.length() - 1, false);
    cout << str;
}
