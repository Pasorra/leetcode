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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode();
        ListNode *val0 = new ListNode(0);
        ListNode *resHead = res;
        ListNode *prevRes;
        while (l1 && l2)
        {
            calculate(l1, l2, res, prevRes);
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            calculate(l1, val0, res, prevRes);
            l1 = l1->next;
        }
        while (l2)
        {
            calculate(val0, l2, res, prevRes);
            l2 = l2->next;
        }
        prevRes->next = carry == 1 ? new ListNode(1) : nullptr;
        return resHead;
    }

private:
    int carry = 0;

    void calculate(ListNode *l1, ListNode *l2, ListNode *&res, ListNode *&prevRes)
    {
        int val = l1->val + l2->val + carry;
        carry = val / 10;
        res->val = val % 10;
        res->next = new ListNode();
        prevRes = res;
        res = res->next;
    }
};

int main()
{
    Solution *s = new Solution();
    ListNode *l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(9);

    ListNode *res = s->addTwoNumbers(l1, l2);
    while (res)
    {
        cout << res->val << ", ";
        res = res->next;
    }
    cout << endl;
    return 0;
}