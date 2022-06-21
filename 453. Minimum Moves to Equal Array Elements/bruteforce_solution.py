class Solution:
    def minMoves(self, nums: list[int]) -> int:
        numRequired = max(nums)
        turns = 0
        while True:
            lastNotIncremented = []
            n = len(nums) - 1
            for i in range(n + 1):
                if nums[i] < numRequired:
                    nums[i] += 1
                    n -= 1
                else:
                    lastNotIncremented.append(i)
                if n == 0:
                    break
            if(n == len(nums) - 1):
                return turns
            elif n != 0:
                numRequired += 1
                for i in range(n):
                    nums[lastNotIncremented[i]] += 1
            turns += 1 
        



sol = Solution()
print(sol.minMoves([1,5,8]))