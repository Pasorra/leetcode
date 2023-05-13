# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def nodeToArray(self, root: TreeNode) -> list[TreeNode]:
        arr = [root]
        if root.left is not None:
            arr += self.nodeToArray(root.left)
        if root.right is not None:
            arr += self.nodeToArray(root.right)
        return arr

    def delNodes(self, root: TreeNode, to_delete: list[int]) -> list[TreeNode]:
        nodesArr = self.nodeToArray(root)
        nodesArr = [x for x in nodesArr if not (x.val in to_delete)]
        notToAdd = []
        res = []
        for node in nodesArr:
            if node.left is not None and node.left.val in to_delete:
                node.left = None
            if node.right is not None and node.right.val in to_delete:
                node.right = None
            notToAdd.append(node.left)
            notToAdd.append(node.right)
        for node in nodesArr:
            if node not in notToAdd:
                res.append(node)
        return res


sol = Solution()

ans = sol.delNodes(TreeNode(1,  TreeNode(2,  TreeNode(4,  None,  None),  TreeNode(5,  None,
                                                                                  None)),  TreeNode(3,  TreeNode(6,  None,  None),  TreeNode(7,  None,  None))), [3, 5])

for a in ans:
    print(a.val)
