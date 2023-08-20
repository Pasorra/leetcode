class Solution:    
    def minSpaceWastedKResizing(self, nums: list[int], k: int) -> int:
        wasted = 0
        current = nums[0]
        for i in range(len(nums) - 1):
            if k != 0 and current < nums[i + 1]:
                k -= 1
                current = nums[i + 1]
            else:
                wasted += current - nums[i + 1]
        if k == 0:
            return wasted
        
sol = Solution()

print(sol.minSpaceWastedKResizing([10,20,15,30,20], 2))
        
        
                