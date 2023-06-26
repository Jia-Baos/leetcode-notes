#include <bits/stdc++.h>

int Solution(std::vector<int> &vec)
{
    int k = 3;
    std::vector<int> temp(vec.size(), 0);
    for (size_t i = 0; i < k; i++)
    {
        temp[i] = vec[vec.size() - k + i];
    }
    for (size_t i = k; i < vec.size(); i++)
    {
        temp[i] = vec[i - k];
    }

    vec = temp;

    return 0;
}

int main(int argc, char *argv[])
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};

    int ans = Solution(vec);

    std::cout << "ans: " << ans << std::endl;

    for (auto &iter : vec)
    {
        std::cout << iter << std::endl;
    }

    return 0;
}