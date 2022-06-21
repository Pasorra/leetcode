class Solution:
    def minPatches(self, nums: list, n: int) -> int:
        requiredPatches = summedNum = i = 0
        nums.sort()
        while summedNum < n:
            try:
                if nums[i] - summedNum <= 1: summedNum += nums[i]
                else:
                    nums.insert(i, summedNum + 1)
                    requiredPatches += 1
                    summedNum += summedNum + 1
                i += 1
            except:
                while summedNum < n:
                    summedNum += summedNum + 1
                    requiredPatches += 1
        return requiredPatches        
                            
        
sol = Solution()
print(sol.minPatches([1,2,31,33], 2147483647))        