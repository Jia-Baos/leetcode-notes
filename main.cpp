#include <bits/stdc++.h>

int Solution(std::vector<int> &vec, std::vector<int> &temp)
{
    for (size_t i = 1; i < vec.size(); i++)
    {
        int j = i;
        int temp = vec[i];

        while (j > 0 && vec[j - 1] > temp)
        {
            vec[j] = vec[j - 1];
            j -= 1;
        }

        vec[j] = temp;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    std::vector<int> vec = {6, 2, 3, 5, 1, 4};
    std::vector<int> temp;
    int ans = Solution(vec, temp);

    std::cout << "ans: " << ans << std::endl;

    for (auto &iter : vec)
    {
        std::cout << iter << std::endl;
    }

    return 0;
}