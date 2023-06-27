#include <bits/stdc++.h>

int Solution(std::vector<int> &vec)
{

    int ans = 0;

    if (vec.size() < 2)
    {
        ans = 0;
    }
    if (vec.size() == 2)
    {
        ans = std::abs(vec[0] - vec[1]);
    }

    int max = *std::max_element(vec.begin(), vec.end());

    std::vector<int> counts(max + 1);
    for (auto &iter : vec)
    {
        counts[iter] += 1;
    }

    int index = 0;
    for (size_t i = 0; i < counts.size(); i++)
    {
        while (counts[i] > 0)
        {
            vec[index++] = i;
            counts[i] -= 1;
        }
    }

    // 对已排序的序列计算相邻两元素的最大差值
    for (size_t i = 1; i < vec.size(); i++)
    {
        if (std::abs(vec[i] - vec[i - 1]) > ans)
        {
            ans = std::abs(vec[i] - vec[i - 1]);
        }
    }

    return ans;
}

int main(int argc, char *argv[])
{
    std::vector<int> vec = {3, 6, 9, 1};

    int ans = Solution(vec);

    std::cout << "ans: " << ans << std::endl;

    for (auto &iter : vec)
    {
        std::cout << iter << std::endl;
    }

    return 0;
}