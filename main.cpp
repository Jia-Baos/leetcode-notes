#include <bits/stdc++.h>

struct ListNode
{
    int val_;
    ListNode *next_;
    ListNode(int val) : val_(val), next_(nullptr) {}
};

int Solution(ListNode *head)
{
    int flag = 1;
    std::set<ListNode *> node_set;
    ListNode *iter = head;
    while (iter)
    {
        if (node_set.find(iter) != node_set.end())
        {
            flag = 0;
            break;
        }
        else
        {
            node_set.insert(iter);
            iter = iter->next_;
        }
    }

    std::cout << "The first node's value: " << iter->val_ << std::endl;

    return flag;
}

int main(int argc, char *argv[])
{

    ListNode *listnode0 = new ListNode(3);
    ListNode *listnode1 = new ListNode(2);
    ListNode *listnode2 = new ListNode(0);
    ListNode *listnode3 = new ListNode(4);
    listnode0->next_ = listnode1;
    listnode1->next_ = listnode2;
    listnode2->next_ = listnode3;
    listnode3->next_ = listnode1;

    int val = Solution(listnode0);

    std::cout << val << std::endl;

    return 0;
}