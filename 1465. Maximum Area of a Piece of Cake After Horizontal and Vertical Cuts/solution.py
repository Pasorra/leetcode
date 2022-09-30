class Solution:
    def findMax(self, cuts: list[int], size):
        cuts = sorted(cuts)    
        last = 0
        max = 0
        for i in cuts:
            if i - last > max:
                max = i - last
            last = i
        max = max if size - cuts[-1] < max else size - cuts[-1] 
        return max
        
    def maxArea(self, h: int, w: int, horizontalCuts: list[int], verticalCuts: list[int]) -> int:
        maxH =  self.findMax(horizontalCuts, h)
        maxW =  self.findMax(verticalCuts, w)
        return (maxH * maxW) % 1000000007
    
    
sol = Solution()
sol.maxArea(5, 4, [3,1], [1])