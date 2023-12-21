#include <iostream>
#include <vector>
#include <algorithm>
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
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> vals;
        rootToVector(root, vals);
        sort(vals.begin(), vals.end());
        int res = INT32_MAX;
        for (int i = 0; i < vals.size() - 1; i++)
        {
            int temp = vals[i + 1] - vals[i];
            res = min(temp, res);
        }
        return res;
    }
    void rootToVector(TreeNode *root, vector<int> &v)
    {
        if (root)
        {
            v.push_back(root->val);
            rootToVector(root->left, v);
            rootToVector(root->right, v);
        }
    }
};

int main()
{
    Solution *s = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(48);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(49);
    int res = s->getMinimumDifference(root);
    cout << res << endl;
    return 0;
}