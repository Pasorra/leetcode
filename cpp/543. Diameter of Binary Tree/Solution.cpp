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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxVal = 0;
        int left = check(root->left, maxVal);
        int right = check(root->right, maxVal);
        return max(left + right, maxVal);
    }
    int check(TreeNode *root, int &maxVal)
    {
        if (!root)
            return 0;
        cout << root->val << endl;
        if (!root->left && !root->right)
            return 1;
        int leftRes = check(root->left, maxVal);
        int rightRes = check(root->right, maxVal);
        maxVal = max(maxVal, leftRes + rightRes);
        return leftRes > rightRes ? leftRes + 1 : rightRes + 1;
    }
};
int main()
{
    Solution *s = new Solution();

    TreeNode *n = new TreeNode(1);
    n->left = new TreeNode(2);
    n->left->left = new TreeNode(4);
    n->right = new TreeNode(3);
    n->left->right = new TreeNode(5);

    int res = s->diameterOfBinaryTree(n);
    cout << res << endl;
    return 0;
}