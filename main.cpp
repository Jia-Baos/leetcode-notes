#include <bits/stdc++.h>

class MinStack
{
private:
    std::stack<int> val_stack_;
    std::stack<int> min_stack_;

public:
    MinStack()
    {
        min_stack_.push(INT_MAX);
    }

    // 入栈操作
    void push(int val)
    {
        val_stack_.push(val);
        min_stack_.push(std::min(min_stack_.top(), val));
    }

    // 出栈操作
    void pop()
    {
        val_stack_.pop();
        min_stack_.pop();
    }

    // 获取栈顶元素
    int top()
    {
        return val_stack_.top();
    }

    // 获取最小元素
    int getMin()
    {
        return min_stack_.top();
    }
};

int main(int argc, char *argv[])
{

    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout << "Val: " << minStack->getMin() << std::endl;
    minStack->pop();
    std::cout << "Val: " << minStack->top() << std::endl;
    std::cout << "Val: " << minStack->getMin() << std::endl;

    return 0;
}