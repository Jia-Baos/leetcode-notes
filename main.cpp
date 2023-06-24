#include <bits/stdc++.h>

int Solution(std::array<int, 4> &arr)
{
    int k = 3;
    int t = 0;

    std::map<int, int> window;
    int left = 0;
    int right = 0;

    while (right < arr.size())
    {
        window.insert({arr[right], right});

        if (right - left > k)
        {
            window.erase(arr[left]);
            left += 1;
        }

        int idx = arr[right];
        if (idx > 0 && std::abs(window[idx] - window[idx - 1]) <= t)
        {
            return 0;
        }

        if (idx < arr.size() - 1 && std::abs(window[idx + 1] - window[idx]) <= t)
        {
            return 0;
        }

        right += 1;
    }

    return -1;
}

int main(int argc, char *argv[])
{
    std::array<int, 4> arr = {1, 2, 3, 1};

    int dst = Solution(arr);

    std::cout << "dst: " << dst << std::endl;

    return 0;
}