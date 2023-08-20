class Solution:
    def countPairs(self, nums: list[int], low: int, high: int) -> int:
        count = 0
        for i, firstNo in enumerate(nums):
            for secondNo in nums[i + 1:]:
                if low <= firstNo ^ secondNo <= high:
                    count += 1
        return count

sol = Solution()
print(sol.countPairs(newList, 3081, 6573))