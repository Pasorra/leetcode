class Solution:
    def findErrorNums(self, nums: list[int]) -> list[int]:
        dic = {}
        for i in nums:
            try:
                dic[i] += 1
            except:
                dic[i] = 1
        ans = [0, 0]
        for i in range(1, len(nums) + 1):
            try:
                if dic[i] == 2:
                    ans[0] = i
            except:
                ans[1] = i
        return ans


sol = Solution()
print(sol.findErrorNums([1, 1]))
