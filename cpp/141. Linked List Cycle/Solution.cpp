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
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> visitedNodes;
        while (true)
        {
            if (!head)
            {
                break;
            }
            visitedNodes.insert(head);
            if (visitedNodes.find(head->next) != visitedNodes.end())
            {
                return true;
            }
            head = head->next;
        }
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    int res = s->hasCycle(head);
    cout << res << endl;
}