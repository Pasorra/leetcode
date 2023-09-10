#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> visitedNodes;
        while (headA)
        {
            visitedNodes.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (visitedNodes.find(headB) != visitedNodes.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

int main()
{
    Solution *s = new Solution();
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;
    ListNode *res = s->getIntersectionNode(headA, headB);
    cout << res->val << endl;
}