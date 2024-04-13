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
    int findTilt(TreeNode *root)
    {
        calculate(root);
        return res;
    }
    int calculate(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = calculate(root->left);
        int right = calculate(root->right);
        res += abs(left - right);
        return root->val + left + right;
    }

private:
    int res = 0;
};

int main()
{
    Solution *s = new Solution();
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);
    int res = s->findTilt(root);
    cout << res << endl;
    return 0;
}