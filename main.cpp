#include <bits/stdc++.h>

int Solution(std::vector<int> &vec)
{
    int left = 0;
    int right = vec.size() - 1;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (vec[mid] > vec[right])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}

int main(int argc, char *argv[])
{
    std::vector<int> vec = {4, 5, 6, 7, 0, 1, 2};

    int ans = Solution(vec);

    std::cout << "ans: " << ans << std::endl;

    for (auto &iter : vec)
    {
        std::cout << iter << std::endl;
    }

    return 0;
}