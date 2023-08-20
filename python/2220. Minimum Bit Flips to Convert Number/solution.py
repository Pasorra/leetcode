class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        if goal > start:
            return self.minBitFlips(goal, start)
        count = 0
        start = bin(start)[2:]
        goal = bin(goal)[2:]
        i = len(start) - len(goal)
        goal = ("0" * i) + goal
        for i in range(len(goal)):
            if goal[i] != start[i]:
                count += 1
        return count
            
        

sol = Solution()
print(sol.minBitFlips(100,5))