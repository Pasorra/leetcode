class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
class Solution:
    def sortedArrayToBST(self, nums: list[int]) -> TreeNode:
        iMiddle = int(len(nums) / 2)
        iLeft = iMiddle - 1
        iRight = iMiddle + 1
        if iLeft >= 0 and iRight < len(nums):
            node = TreeNode(nums[iMiddle], self.sortedArrayToBST(nums[:iLeft + 1]), self.sortedArrayToBST(nums[iRight:]))
        elif iLeft >= 0:
            node = TreeNode(nums[iMiddle], self.sortedArrayToBST(nums[:iLeft + 1]), None)
        elif iRight < len(nums):
            node = TreeNode(nums[iMiddle], None, self.sortedArrayToBST(nums[iRight:]))  
        else:
            node = TreeNode(nums[iMiddle], None, None)    
        return node
    

sol = Solution()
print(sol.sortedArrayToBST([-10,-3,0,5,9]).val)
