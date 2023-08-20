class Solution:
    def DFS(number, indexes: list, noOfIterationsLeft, arr, newArr: set):
        if(noOfIterationsLeft <= 0):
            return
        for index, val in enumerate(arr):
            if(index in indexes):
                continue
            newArr.add(number+val)
            newIndexes = indexes.copy()
            newIndexes.append(index)
            Solution.DFS(number + val, newIndexes, noOfIterationsLeft - 1, arr, newArr)
    def minPatches(self, nums, n: int) -> int:
        requiredPatches = 0
        sums = set()
        while True:
            maxNo = sum(nums)
            requiredNums = [x for x in range(1, maxNo)]   
            for x in range(len(nums)):
                sums.add(nums[x])
                startIndexes = [x]
                Solution.DFS(nums[x], startIndexes, len(nums) - 1, nums, sums)
            for x in sums:
                try:
                    requiredNums.remove(x)
                except:
                    pass
            print(str(sum(nums)) + ":" + str(max(sums)))
            if(len(requiredNums) == 0):
                if maxNo >= n:
                    return requiredPatches
                break
            nums.append(requiredNums[0])
            requiredPatches += 1
        summedNum = sum(nums)
        while summedNum < n:
            summedNum += summedNum + 1
            requiredPatches += 1
        return requiredPatches
            
sol = Solution()
print(sol.minPatches([2,4,14,18,20,25,25,35,73,94], 42))