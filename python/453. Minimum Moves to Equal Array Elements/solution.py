class Solution:
    def minMoves(self, nums: list[int]) -> int:
        minNum = min(nums)
        moves = 0
        for i in nums:
            moves += i - minNum 
        return moves


sol = Solution()

print(sol.minMoves([1,5,8]))