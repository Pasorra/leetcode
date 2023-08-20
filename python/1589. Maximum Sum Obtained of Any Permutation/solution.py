#BETTER SOLUTION AT https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/discuss/854206/JavaC%2B%2BPython-Sweep-Line

import numpy as np

class Solution:
    def maxSumRangeQuery(self, nums: list[int], requests: list[list[int]]) -> int:
        requestsArr = np.zeros(max(map(max, requests)) + 1)
        for req in requests:
            requestsArr[req[0] : req[1] + 1] += 1
        requestsArr.sort()
        nums = sorted(nums)
        sum = 0
        index = len(nums) - 1
        for i in requestsArr[-1::-1]:
            if i == 0:
                break
            sum += nums[index] * i
            index -= 1
        return int(sum) % 1000000007
    
sol = Solution()
print(sol.maxSumRangeQuery([1,8,5,5,2],
                           [[4,4],[3,4],[4,4],[2,4],[0,0]]))        
        