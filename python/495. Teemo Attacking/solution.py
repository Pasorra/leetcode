class Solution:
    def findPoisonedDuration(self, timeSeries: list[int], duration: int) -> int:
        totalDuration = 0
        for i, time in enumerate(timeSeries):
            if(i == len(timeSeries) - 1):
                totalDuration += duration
                return totalDuration
            totalDuration += min(duration, timeSeries[i + 1] - time)
        
        
        
sol = Solution
print(sol.findPoisonedDuration(sol, [1,2], 2))
