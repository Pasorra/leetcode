class Solution:
    def countBits(self, n: int) -> list[int]:
        ans = []
        for i in range(n + 1):
            binary = str(bin(i))[2:]
            ans.append(sum([int(x) for x in binary]))
        return ans