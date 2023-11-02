#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root, bool isLeft = false)
    {
        if (!root)
        {
            return 0;
        }

        int result = 0;
        if (isLeft && !root->left && !root->right)
        {
            return result + root->val;
        }
        result += sumOfLeftLeaves(root->left, true);
        result += sumOfLeftLeaves(root->right, false);
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->sumOfLeftLeaves();
    cout << res << endl;
    return 0;
}