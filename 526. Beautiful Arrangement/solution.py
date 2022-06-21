class Solution:
    def check(self, index, numsForIndexes, arr: list, n, counter):
        try:
            for i in numsForIndexes[index]:
                if i not in arr:
                    arr.append(i)
                    counter = self.check(index + 1, numsForIndexes, arr, n, counter)
                    arr.remove(i)
        except IndexError:
            return counter + 1
        return counter
    
    def countArrangement(self, n: int) -> int:
        numsForIndexes = [[] for _ in range(n)]
        for i in range(n):
            for x in range(n):
                if (i + 1) % (x + 1) == 0 or (x + 1) % (i + 1) == 0:
                    numsForIndexes[i].append(x + 1)
        return self.check(0, numsForIndexes, [], n, 0)
    

sol = Solution()
print(sol.countArrangement(4))