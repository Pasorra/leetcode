#include <iostream>
#include <vector>
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
    bool isBalanced(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return abs(leftDepth - rightDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    int maxDepth(TreeNode *root, int result = 0)
    {
        if (!root)
        {
            return result;
        }
        result++;
        int leftResult = maxDepth(root->left, result);
        int rightResult = maxDepth(root->right, result);

        return max(leftResult, rightResult);
    }
};

int main()
{
    Solution *s = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    int res = s->isBalanced(root);
    cout << res << endl;
}