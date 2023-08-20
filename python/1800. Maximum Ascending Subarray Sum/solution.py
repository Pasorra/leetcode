class Solution:
    def maxAscendingSum(self, nums: list[int]) -> int:
        max = 0
        current = nums[0]
        for i in range(len(nums) - 1):
            if nums[i] < nums[i + 1]:
                current += nums[i + 1]
            else:
                max = current if current > max else max
                current = nums[i + 1]    
        return current if current > max else max  
    
    
sol = Solution()
print(sol.maxAscendingSum([10,20,30,5,10,50]))