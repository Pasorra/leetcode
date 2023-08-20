import math


class Solution:
    def GetDistance(x1, x2, y1, y2, radius):
        return math.sqrt((x1 - x2)**2 + (y1 - y2)**2) <= radius
    def countPoints(self, points, queries):
        answers = []
        for query in queries:
            i = 0
            for point in points:
                if (Solution.GetDistance(point[0], query[0], point[1], query[1], query[2])):
                    i += 1
            answers.append(i)
        return answers
    

sol = Solution
points = [[1,3],[3,3],[5,3],[2,2]]
queries = [[2,3,1],[4,3,1],[1,1,2]]
print(sol.countPoints(sol, points, queries))
        