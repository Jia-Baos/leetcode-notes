#include <bits/stdc++.h>

void MergeSortRecursive(std::array<int, 8> &arr, const int left, const int right)
{
    std::array<int, 8> temp = arr;
    if (left >= right)
    {
        return;
    }

    int N = right - left;           // 7
    int mid = (N / 2) + left;       // 3
    int start1 = left;              // 0
    int end1 = mid;                 // 3
    int start2 = mid + 1;           // 4
    int end2 = right;               // 7

    MergeSortRecursive(temp, start1, end1);
    MergeSortRecursive(temp, start2, end2);

    int k = left;
    while (start1 <= end1 && start2 <= end2)
    {
        arr[k++] = temp[start1] < temp[start2] ? temp[start1++] : temp[start2++];
    }
    while (start1 <= end1)
    {
        arr[k++] = temp[start1++];
    }
    while (start2 <= end2)
    {
        arr[k++] = temp[start2++];
    }
}

int main(int argc, char *argv[])
{
    std::array<int, 8> arr = {6, 2, 1, 3, 7, 5, 4, 8};
    MergeSortRecursive(arr, 0, arr.size() - 1);

    for (auto &iter : arr)
    {
        std::cout << iter << std::endl;
    }

    return 0;
}