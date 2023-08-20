class Solution:
    def maxHeight(self, cuboids: list[list[int]]) -> int:
        cuboids = [sorted(cuboid, reverse=True) for cuboid in cuboids]
        cuboids.sort(reverse=True, key=lambda variable: variable[0])
        results = []
        for x in range(len(cuboids) - 1):
            res = cuboids[x][0]
            for i in range(x, len(cuboids)):
                (x1, y1, z1) = cuboids[i]
                (x2, y2, z2) = cuboids[i + 1]
                if x1 < x2 or y1 < y2 or z1 < z2:
                    break
                res += x2
            results.append(res)
        return max(results)


sol = Solution()
print(sol.maxHeight(
    [[36, 46, 41], [15, 100, 100], [75, 91, 59], [13, 82, 64]]))
