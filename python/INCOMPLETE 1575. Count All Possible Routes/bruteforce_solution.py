class Solution:
    def countRoutes(self, locations: list[int], start: int, finish: int, fuel: int, count = 0, solved = []) -> int:
        if fuel <= 0 and start != finish:
            return count
        elif fuel == 0 and start == finish:
            return count + 1
        elif fuel >= 0 and start == finish:
            count += 1 
        for i in range(len(locations)):
            if i == start:
                continue
            x = abs(locations[start] - locations[i])
            count = self.countRoutes(locations, i, finish, fuel - x, count)
        return count

sol = Solution()
print(sol.countRoutes([2,3,6,8,4], 1, 3, 5))
