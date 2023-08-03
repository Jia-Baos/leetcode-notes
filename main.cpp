#include <bits/stdc++.h>

template <typename T>
class Stack
{
private:
    std::vector<T> Stack_;
    int size_;
    int top_;

public:
    // 初始化空栈
    Stack() : size_(100), top_(-1) {}

    // 判断栈是否为空
    [[nodiscard("no discard")]] int is_empty() const
    {
        return this->top_ == -1;
    }

    // 判断栈是否已满
    [[nodiscard("no discard")]] int is_full() const
    {
        return this->top_ + 1 == this->size_;
    }

    // 入栈操作
    void push(T value)
    {
        if (this->is_full())
        {
            std::cerr << "Error: Stack is full" << std::endl;
            exit(-1);
        }
        else
        {
            this->Stack_.push_back(value);
            this->top_ += 1;
        }
    }

    // 出栈操作
    void pop()
    {
        if (this->is_empty())
        {
            std::cerr << "Error: Stack is empty" << std::endl;
            exit(-1);
        }
        else
        {
            this->Stack_.pop_back();
            this->top_ -= 1;
        }
    }

    // 获取栈顶元素
    [[nodiscard("no discard")]] T peek() const
    {
        if (this->is_full())
        {
            std::cerr << "Error: Stack is full" << std::endl;
            exit(-1);
        }
        else
        {
            return this->Stack_[this->top_];
        }
    }
};

int Solution(const std::string &str)
{
    char op = '+';
    int index = 0;
    auto *stack = new Stack<int>();

    while (index < str.size())
    {
        if (str[index] == ' ')
        {
            index += 1;
            continue;
        }

        int num = str[index] - '0';
        if (std::isdigit(str[index]))
        {
            while (index + 1 < str.size() && std::isdigit(str[index + 1]))
            {
                num = 10 * num + str[index + 1] - '0';
                index += 1;
            }

            if (op == '+')
            {
                stack->push(num);
            }
            else if (op == '-')
            {
                stack->push(-num);
            }
            else if (!stack->is_empty() && op == '*')
            {
                int top = stack->peek();
                stack->pop();
                stack->push(top * num);
            }
            else if (!stack->is_empty() && op == '/')
            {
                int top = stack->peek();
                stack->pop();
                stack->push(top / num);
            }
        }

        if (str[index] == '+' || str[index] == '-' || str[index] == '*' || str[index] == '/')
        {
            op = str[index];
        }
        index += 1;
    }

    int sum = 0;
    while (!stack->is_empty())
    {
        sum += stack->peek();
        stack->pop();
    }

    return sum;
}

int main(int argc, char *argv[])
{

    std::string str = " 3+20*2 ";

    int val = Solution(str);

    std::cout << val << std::endl;

    return 0;
}