# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def addOneRow(self, root: TreeNode, val: int, depth: int) -> TreeNode:
        if depth == 2:
            if root != None and root.left != None:
                leftRoot = TreeNode(val, root.left, None) or None
                root.left = leftRoot
            if root != None and root.right != None:
                rightRoot = TreeNode(val, None, root.right) or None
                root.right = rightRoot
            return root
        self.addOneRow(root.left, val, depth - 1)
        self.addOneRow(root.right, val, depth - 1)
        return root


sol = Solution()
ans = sol.addOneRow(TreeNode(2, TreeNode(4, None, None), None), TreeNode(3, None,  None), TreeNode(
    1, TreeNode(2,  TreeNode(4,  None,  None),  None),  TreeNode(3,  None,  None)))
print(ans.left, ans.right, ans.val)
