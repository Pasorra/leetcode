from math import sqrt


class Solution:
    def getMinDistSum(self, positions: list[list[int]]) -> float:
        sumX = 0
        sumY = 0
        for pos in positions:
            sumX += pos[0]
            sumY += pos[1]
        centreX = sumX / len(positions)
        centreY = sumY / len(positions)
        finalDist = 0
        for pos in positions:
            finalDist += (sqrt(((centreX - pos[0]) ** 2) + ((centreY - pos[1]) ** 2)))
        return finalDist
        
        
sol = Solution()
print(sol.getMinDistSum([[1,1],[3,3]]))