class Solution:
    def maxResult(self, nums: list[int], k: int) -> int:
        i = 0
        result = nums[0]
        while True:
            jumpRange = [i + 1, min(len(nums) - 1, i + k)]
            biggest = []
            secondaryIndex = 0
            shouldBreak = False
            for num in nums[jumpRange[0]: jumpRange[1] + 1]:
                i += 1
                if num >= 0:
                    result += num
                    shouldBreak = True
                    break
                else:
                    biggest.append([num, i])
                    for big in enumerate(biggest[:secondaryIndex]):
                        biggest[big[0]][0] += num
                    secondaryIndex += 1
            if not shouldBreak:
                big = max(biggest, key=lambda x: x[0])
                result += big[0]
                i = big[1]
            if i + 1 == len(nums):
                break

        return result


sol = Solution()
print(sol.maxResult([1, -1, -2, 4, -7, 3], 2))
