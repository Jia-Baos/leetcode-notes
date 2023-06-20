#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    std::array<int, 8> arr = {6, 2, 1, 3, 7, 5, 4, 8};

    int gap = arr.size() / 2;

    while (gap > 0)
    {
        for (size_t i = gap; i < arr.size(); i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }

        gap /= 2;
    }

    for (auto &iter : arr)
    {
        std::cout << iter << std::endl;
    }

    return 0;
}