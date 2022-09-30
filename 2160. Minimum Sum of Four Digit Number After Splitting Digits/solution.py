class Solution:
    def minimumSum(self, num: int) -> int:
        num = [int(x) for x in str(num)]
        num = sorted(num)
        return (num[0] * 10) + (num[1] * 10) + num[2] + num[3]


sol = Solution()
print(sol.minimumSum(4009))
