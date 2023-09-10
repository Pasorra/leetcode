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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *parent;
        ListNode *parentToReturn;
        while (head)
        {
            if (head->val != val)
            {
                parent = head;
                parentToReturn = head;
                head = head->next;
                break;
            }
            head = head->next;
        }
        while (head)
        {
            if (head->val == val)
            {
                parent->next = head->next;
                head = head->next;
                continue;
            }
            parent = head;
            head = head->next;
        }
        return parentToReturn;
    }
};

int main()
{
    Solution *s = new Solution();
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    ListNode *res = s->removeElements(head, 6);
    while (res)
    {
        cout << res->val << ", ";
        res = res->next;
    }
    cout << endl;
}