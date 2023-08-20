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
            Solution.DFS(number + val, newIndexes,
                         noOfIterationsLeft - 1, arr, newArr)

    def CalculateSums(lastSummedIndex, i, sums, nums):
        rangedNums = range(lastSummedIndex, i + 2)
        for x in rangedNums:
            sums.add(nums[x])
            startIndexes = [x]
            Solution.DFS(nums[x], startIndexes, i + 1, nums, sums)

    def CalculateSumsFast(sums, addedNumber):
        sumsCopy = list(sums)
        sums.add(addedNumber)
        for x in sumsCopy:
            sums.add(x + addedNumber)

    def minPatches(self, nums: list, n: int) -> int:
        requiredPatches = 0
        uniqueNums = set()
        if 1 not in nums:
            nums.append(1)
            requiredPatches += 1
        for i, x in enumerate(nums):
            sumBetweenNums = x
            uniqueNums.add(x)
            for y in nums[i + 1:]:
                if(x == y):
                    sumBetweenNums += x
                    uniqueNums.add(sumBetweenNums)
                uniqueNums.add(y)
        nums = list(uniqueNums)
        nums.sort()
        nums = [x for x in nums if x <= n]
        sums = set(nums)
        shouldBreak = True
        shouldRestart = False
        lastSummedIndex = 0
        while True:
            for i, x in enumerate(nums):
                if(i != len(nums) - 1 and nums[i+1] - x != 1):
                    for check in range(x + 1, nums[i+1] + 1):
                        if check not in sums:
                            Solution.CalculateSums(
                                lastSummedIndex, i, sums, nums)
                            lastSummedIndex = i
                            if check in sums:
                                continue
                            nums.append(check)
                            requiredPatches += 1
                            shouldBreak = False
                            shouldRestart = True
                            break
                if shouldRestart:
                    break
            if shouldBreak:
                break
            shouldBreak = True
            shouldRestart = False
            nums.sort()
        summedNum = sum(nums)
        while summedNum < n:
            summedNum += summedNum + 1
            requiredPatches += 1
        return requiredPatches


sol = Solution()
print(sol.minPatches([4,5,7,7,9,11,12,33,35,39,40,50,54,59,60,60,66,70,71,72,77,78,81,84,84,84,85,88,95,96,96], 36))
