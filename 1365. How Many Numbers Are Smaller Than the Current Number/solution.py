from collections import OrderedDict


class Solution:
    def smallerNumbersThanCurrent(self, nums: list[int]) -> list[int]:
        newNums = {}
        for num in nums:
            try:
                newNums[num] += 1 
            except:
                newNums[num] = 1
        for i in range(len(nums)):
            count = 0
            for key, val in newNums.items():
                if key < nums[i]:
                    count += val
            nums[i] = count
        return nums            
                
sol = Solution()
print(sol.smallerNumbersThanCurrent([6,5,4,8]))