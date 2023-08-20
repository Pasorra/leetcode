class Solution:
    def fib(self, n: int) -> int:
        if(n <= 0):
            return 0
        if(n == 1):
            return 1
        return Solution.fib(self, n-1) + Solution.fib(self, n-2 )
    
    
sol = Solution 
print(sol.fib(sol, 8))