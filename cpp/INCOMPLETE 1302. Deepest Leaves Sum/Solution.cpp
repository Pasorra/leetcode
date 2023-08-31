#include <vector>
#include <iostream>
using namespace std;

class Solution
{

    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    int deepestLeavesSum(TreeNode *root)
    {
    }
};

int main()
{
    Solution *s = new Solution();
    int result = s->deepestLeavesSum(234);
    cout << "Result: " << result << endl;
    return 0;
}