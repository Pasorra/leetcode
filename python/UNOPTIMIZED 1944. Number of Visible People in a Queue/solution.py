class Solution:
    def canSeePersonsCount(self, heights: list[int]) -> list[int]:
        answer = [0 for _ in range(len(heights))]
        for personIndex in range(len(heights)):
            maxPersonHeight = 0
            personHeight = heights[personIndex]
            for rightPersonIndex in range(personIndex + 1, len(heights)):
                if maxPersonHeight < personHeight and maxPersonHeight < heights[rightPersonIndex]:
                    answer[personIndex] += 1
                maxPersonHeight = maxPersonHeight if heights[
                    rightPersonIndex] < maxPersonHeight else heights[rightPersonIndex]
        return answer


sol = Solution()
print(sol.canSeePersonsCount([10, 6, 8, 5, 11, 9]))
