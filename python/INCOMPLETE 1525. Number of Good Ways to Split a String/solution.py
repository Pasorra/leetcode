#TOO SLOW

class Solution:
    def CheckToRight(s, i):
        count = 0
        while True:
            left = len(set(s[:i])) 
            right =  len(set(s[i:]))
            if left == right:
                count += 1
            if right < left:
                return count
            i += 1
            if(i == len(s)):
                return count
    def CheckToLeft(s, i):
        count = 0
        while True:
            left = len(set(s[:i])) 
            right = len(set(s[i:]))
            if left == right:
                count += 1
            if right > left:
                return count
            i -= 1
            if(i == 0):
                return count    
    def numSplits(self, s: str) -> int:
        i = int(len(s) / 2)
        arr = list(s)
        return Solution.CheckToLeft(arr, i - 1) + Solution.CheckToRight(arr, i)
        
            
        
        
sol = Solution
print(sol.numSplits(sol, "aabacas"))