from itertools import permutations


class Solution:
    def countArrangement(self, n: int) -> int:
        perms = [x + 1 for x in range(n)]
        perms = list(permutations(perms, n))
        count = 0
        for perm in perms:
            for i, x in enumerate(perm):
                if ((i + 1) % x != 0) and (x % (i + 1)) != 0:
                    break
                if i == n - 1:
                    count += 1
                    print(perm)
        return count
    

sol = Solution()
print(sol.countArrangement(4))