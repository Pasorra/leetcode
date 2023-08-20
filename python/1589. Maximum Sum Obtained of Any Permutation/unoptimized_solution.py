class Solution:
    def maxSumRangeQuery(self, nums: list[int], requests: list[list[int]]) -> int:
        reqDict = {}
        for req in requests:
            for i in range(req[0], req[1] + 1):
                try:
                    reqDict[i] += 1
                except:
                    reqDict[i] = 1
        reqDict = sorted(reqDict.items(), key=lambda item: item[1], reverse=True)
        nums = sorted(nums)
        sum = 0
        index = len(nums) - 1
        for _, i in reqDict:
            sum += nums[index] * i
            index -= 1
        return sum
    
sol = Solution()
print(sol.maxSumRangeQuery([1,2,3,4,5,6], [[0,1]]))        
        