class Solution:
    def maxScore(self, cardPoints, k: int) -> int:
        if k == len(cardPoints):
            return(sum(cardPoints))
        
        numsInARowToSum = len(cardPoints) - k
        i = 0
        try:
            count = 0
            for x in range(i, i + numsInARowToSum):
                count += cardPoints[x]
            smallest = count
            while True:
                count -= cardPoints[i]
                count += cardPoints[i + numsInARowToSum]
                smallest = count if count <= smallest else smallest
                i += 1
        except IndexError:
            return sum(cardPoints) - smallest
        
sol = Solution()
print(sol.maxScore([1,2,3,4,5,6,1], 3))