#include <iostream>
#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        if (!root->left && !root->right)
        {
            result.push_back(to_string(root->val));
            return result;
        }
        dive(root, result);
        return result;
    }
    void dive(TreeNode *root, vector<string> &result, string pathSoFar = "")
    {
        if (!root)
        {
            return;
        }
        if (pathSoFar == "")
        {
            pathSoFar += to_string(root->val);
        }
        else
        {
            pathSoFar += "->" + to_string(root->val);
        }
        if (!root->left && !root->right)
        {
            result.push_back(pathSoFar);
            return;
        }
        dive(root->left, result, pathSoFar);
        dive(root->right, result, pathSoFar);
        return;
    }
};

int main()
{
    Solution *s = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    vector<string> res = s->binaryTreePaths(root);
    for (auto val : res)
    {
        cout << val << ", ";
    }
    cout << endl;
    return 0;
}