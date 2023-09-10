#include <iostream>
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
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *prev = head;
        ListNode *temp;
        head = head->next;
        prev->next = nullptr;
        while (head)
        {
            temp = head->next; // 3
            head->next = prev; // 6 -> 2-> 1
            prev = head;       // 2
            head = temp;       // 6
        }
        return prev;
    }
};

int main()
{
    Solution *s = new Solution();
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    ListNode *res = s->reverseList(head);
    while (res)
    {
        cout << res->val << ", ";
        res = res->next;
    }
    cout << endl;
}