#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    int k = 3;
    int t = 0;
    bool flag = false;
    std::array<int, 4> arr = {1, 2, 3, 1};

    std::map<int, int> dict;
    for (size_t i = 0; i < arr.size(); i++)
    {
        int index = arr[i] / (t + 1);

        // 若目前桶已存在。说明前面已经有 [index - t, index + t]
        if (dict.find(index) != dict.end())
        {
            flag = true;
            break;
        }

        // 检查左侧的桶
        if (dict.find(index - 1) != dict.end() && std::abs(dict[index - 1] - arr[i]) <= t)
        {
            flag = true;
            break;
        }

        // 检测右侧的桶
        if (dict.find(index + 1) != dict.end() && std::abs(dict[index + 1] - arr[i]) <= t)
        {
            flag = true;
            break;
        }

        // 建立目标桶
        dict.insert({index, arr[i]});

        // 移除下标范围不在[i-k, i]内的桶
        if (i >= k)
        {
            dict.erase(arr[i - k] / (t + 1));
        }
    }

    std::cout << flag << std::endl;

    return 0;
}