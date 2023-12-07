#include <iostream>
#include <vector>
#include <unordered_map>
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
    vector<int> findMode(TreeNode *root)
    {
        unordered_map<int, int> map;
        int maxAmount = checkMaxOccurrence(map, root);
        vector<int> res;
        for (auto kv : map)
        {
            if (kv.second == maxAmount)
            {
                res.push_back(kv.first);
            }
        }
        return res;
    }

private:
    int checkMaxOccurrence(unordered_map<int, int> &map, const TreeNode *root, int maxAmount = 0)
    {
        if (root)
        {
            map[root->val]++;
            maxAmount = max(maxAmount, map[root->val]);
            maxAmount = max(maxAmount, checkMaxOccurrence(map, root->left, maxAmount));
            maxAmount = max(maxAmount, checkMaxOccurrence(map, root->right, maxAmount));
        }
        return maxAmount;
    }
};

int main()
{
    Solution *s = new Solution();
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    vector<int> res = s->findMode(root);
    printVector(res);
    return 0;
}