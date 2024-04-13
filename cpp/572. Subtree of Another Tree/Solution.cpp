#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(const vector<T> &v)
{
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << endl;
}

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
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;
        return check(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool check(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
            return true;

        // (!root && subRoot) || (root && !subRoot)
        else if (!!(root) ^ !!(subRoot))
        {
            return false;
        }

        if (root->val == subRoot->val)
        {
            return check(root->left, subRoot->left) && check(root->right, subRoot->right);
        }
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(2);

    TreeNode *subRoot = new TreeNode(3);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);
    int res = s->isSubtree(root, subRoot);
    cout << res << endl;
    return 0;
}