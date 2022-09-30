class Solution:
    def getConcatenation(self, nums: list[int]) -> list[int]:
        length = len(nums)
        for i, num in enumerate(nums):
            if i == length:
                break
            nums.append(num)
        return nums