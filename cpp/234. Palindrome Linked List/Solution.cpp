#include <iostream>
#include <vector>
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
    bool isPalindrome(ListNode *head)
    {
        vector<int> numbers;
        while (head)
        {
            numbers.push_back(head->val);
            head = head->next;
        }
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            if (numbers[left] != numbers[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next = new ListNode(1);
    bool res = s->isPalindrome(head);
    cout << res << endl;
    return 0;
}