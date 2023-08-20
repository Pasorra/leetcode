class Solution:
    def canWinNim(self, n: int) -> bool:
        return not (n % 4 == 0)
        
sol = Solution
print(sol.canWinNim(sol, 5))