class Solution:
    def leastOpsExpressTarget(self, x: int, target: int) -> int:
        i = 0
        num = x
        while True:
            if(num == target):
                return i
            num *= x
            i += 1
            if(num > target):
                num /= x
                i -= 1
                break
        while True:
            if(num == target):
                return i
            num += x
            i += 1
            if(num > target):
                num -= x
                i -= 1
                break
        while True:
            if(num == target):
                return i
            num += 1
            i += 1

sol = Solution()
print(sol.leastOpsExpressTarget(5, 501))