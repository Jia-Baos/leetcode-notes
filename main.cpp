#include <bits/stdc++.h>

struct RandomListNode
{
    int val_;
    RandomListNode *next_;
    RandomListNode *random_;
    RandomListNode(int val) : val_(val),
                              next_(nullptr),
                              random_(nullptr) {}
};

class Solution
{
public:
    std::unordered_map<RandomListNode *, RandomListNode *> cachedNode;

    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (!cachedNode.count(head))
        {
            RandomListNode *headNew = new RandomListNode(head->val_);
            cachedNode[head] = headNew;
            headNew->next_ = copyRandomList(head->next_);
            headNew->random_ = copyRandomList(head->random_);
        }
        return cachedNode[head];
    }
};

int main(int argc, char *argv[])
{

    RandomListNode *listnode0 = new RandomListNode(7);
    RandomListNode *listnode1 = new RandomListNode(13);
    RandomListNode *listnode2 = new RandomListNode(11);
    RandomListNode *listnode3 = new RandomListNode(10);
    RandomListNode *listnode4 = new RandomListNode(1);
    listnode0->next_ = listnode1;
    listnode0->random_ = nullptr;
    listnode1->next_ = listnode2;
    listnode1->random_ = listnode0;
    listnode2->next_ = listnode3;
    listnode2->random_ = listnode4;
    listnode3->next_ = listnode4;
    listnode3->random_ = listnode2;
    listnode4->next_ = nullptr;
    listnode4->random_ = listnode0;

    Solution *solution = new Solution();
    RandomListNode *listnode = solution->copyRandomList(listnode0);

    return 0;
}