#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    std::string str = "Hello";

    for (auto &iter : str)
    {
        if (std::isupper(iter))
        {
            iter = std::tolower(iter);
        }
    }

    std::cout << str << std::endl;

    return 0;
}