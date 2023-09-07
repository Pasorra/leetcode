
// Definition for singly-linked list.
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Check if any of the nodes are empty
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *newList = nullptr;
        ListNode *newListHead = nullptr;
        // Determine the starting node
        if (list1->val > list2->val)
        {
            newList = list2;
            newListHead = list2;
            list2 = list2->next;
        }
        else
        {
            newList = list1;
            newListHead = list1;
            list1 = list1->next;
        }

        while (true)
        {
            if (!(list1) && !(list2))
            {
                return newList;
            }

            if (!(list1))
            {
                newList->next = list2;
                newList = list2;
                list2 = list2->next;
                break;
            }
            else if (!(list2))
            {
                newList->next = list1;
                newList = list1;
                list1 = list1->next;
                break;
            }

            if (list1->val > list2->val)
            {
                newList->next = list2;
                newList = list2;
                list2 = list2->next;
            }
            else
            {
                newList->next = list1;
                newList = list1;
                list1 = list1->next;
            }
        }
        return newListHead;
    }
};

int main()
{
    Solution *s = new Solution();

    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    s->mergeTwoLists(list1, list2);
    return 0;
}