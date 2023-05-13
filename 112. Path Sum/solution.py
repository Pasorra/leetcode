class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        if root is None:
            return False
        targetSum -= root.val
        if targetSum == 0 and root.left is None and root.right is None:
            return True
        leftCheck = self.hasPathSum(root.left, targetSum)
        rightCheck = self.hasPathSum(root.right, targetSum)
        return leftCheck or rightCheck


sol = Solution()
print(sol.hasPathSum(TreeNode(1,  TreeNode(-2,  TreeNode(1,  TreeNode(-1,  None, None),
      None), TreeNode(3,  None, None)), TreeNode(-3,  TreeNode(-2,  None, None), None)), -1))
