#include <bits/stdc++.h>

int Solution(const std::array<int, 7> &arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] > arr[right])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return arr[left];
}

int main(int argc, char *argv[])

{
    int target = 0;
    std::array<int, 7> arr = {4, 5, 6, 7, 0, 1, 2};

    int pos = Solution(arr);

    std::cout << pos << std::endl;

    return 0;
}