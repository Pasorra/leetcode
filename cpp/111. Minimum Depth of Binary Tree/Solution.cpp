#include <iostream>
#include <vector>
#include <limits.h>
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
    int minDepth(TreeNode *root, int result = 1)
    {
        if (!root)
        {
            return result == 1 ? 0 : INT_MAX;
        }
        if (!root->left && !root->right)
        {
            return result;
        }
        result++;
        int leftResult = minDepth(root->left, result);
        int rightResult = minDepth(root->right, result);
        return min(leftResult, rightResult);
    }
};
int main()
{
    Solution *s = new Solution();
    TreeNode *root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(5);
    root->right->right->right->right = new TreeNode(6);

    int res = s->minDepth(root);
    cout << res << endl;
}