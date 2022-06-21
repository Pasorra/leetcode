class Solution:
    def waysToMakeFair(self, nums: list[int]) -> int:
        evenInd = 0
        oddInd = 0
        pastEven = 0
        pastOdd = 0
        isEven = True
        fair = 0
        for num in nums:
            if isEven:
                evenInd += num
                isEven = False
            else: 
                oddInd += num
                isEven = True
        isEven = True
        for num in nums:
            if isEven:
                evenInd -= num
                if evenInd + pastOdd == oddInd + pastEven:
                    fair += 1
                pastEven += num
                isEven = False
            else:
                oddInd -= num
                if evenInd + pastOdd == oddInd + pastEven:
                    fair += 1
                pastOdd += num
                isEven = True
        return fair       
                
sol = Solution()
print(sol.waysToMakeFair([2,1,6,4]))