#include <iostream>
#include <sstream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *child = head->next;
        ListNode *result = head;
        while (head && child)
        {
            if (head->val == child->val)
            {
                head->next = child->next;
                child = child->next;
            }
            else
            {
                head = head->next;
                child = head->next;
            }
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    s->deleteDuplicates(head);

    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val;
        if (current->next != nullptr)
        {
            std::cout << " -> ";
        }
        current = current->next;
    }
}