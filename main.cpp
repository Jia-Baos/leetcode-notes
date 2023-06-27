#include <bits/stdc++.h>

struct ListNode
{
    int val_;
    ListNode *next_;
    ListNode(int val) : val_(val), next_(nullptr) {}
};

class MyLinkerList
{
public:
    int size_;
    ListNode *head_;

public:
    MyLinkerList()
    {
        this->size_ = 0;
        this->head_ = new ListNode(0);
    }

    int get(int index)
    {
        if (index < 0 || index >= this->size_)
        {
            return -1;
        }

        ListNode *cur = this->head_;
        for (size_t i = 0; i <= index; i++)
        {
            cur = cur->next_;
        }

        return cur->val_;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(this->size_, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index > this->size_)
        {
            return;
        }

        index = std::max(0, index);
        this->size_ += 1;

        ListNode *pred = this->head_;
        for (size_t i = 0; i < index; i++)
        {
            pred = pred->next_;
        }

        ListNode *toAdd = new ListNode(val);
        toAdd->next_ = pred->next_;
        pred->next_ = toAdd;
    }

    void deleteAtindex(int index)
    {
        if (index < 0 || index >= this->size_)
        {
            return;
        }

        this->size_ -= 1;
        ListNode *pred = this->head_;
        for (size_t i = 0; i < index; i++)
        {
            pred = pred->next_;
        }

        ListNode *toDelete = pred->next_;
        pred->next_ = pred->next_->next_;

        delete toDelete;
    }
};

ListNode *removeElements(ListNode *head, int target)
{
    ListNode *newhead = head;
    ListNode *iter = newhead;
    while (iter->next_ != nullptr)
    {
        if (iter->next_->val_ == target)
        {
            ListNode *temp = iter->next_;
            iter->next_ = iter->next_->next_;
            delete temp;
        }
        else
        {
            iter = iter->next_;
        }
    }

    return newhead;
}

int main(int argc, char *argv[])
{

    MyLinkerList *linkerlist = new MyLinkerList();
    linkerlist->addAtHead(1);
    linkerlist->addAtTail(2);
    linkerlist->addAtTail(6);
    linkerlist->addAtTail(3);
    linkerlist->addAtTail(4);
    linkerlist->addAtTail(5);
    linkerlist->addAtTail(6);

    ListNode *head = removeElements(linkerlist->head_, 6);

    ListNode *iter = head;
    while (iter)
    {
        std::cout << iter->val_ << std::endl;
        iter = iter->next_;
    }

    return 0;
}