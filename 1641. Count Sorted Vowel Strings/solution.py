class Solution:
    def countVowelStrings(self, n: int, arr: list = [1, 1, 1, 1, 1]) -> int:
        sumOfArr = sum(arr)
        if n == 1:
            return sumOfArr
        newArr = [sumOfArr] * 5
        for i in range(1, 5):
            newArr[i] = newArr[i - 1] - arr[i - 1]
        return self.countVowelStrings(n - 1, newArr)


sol = Solution()
print(sol.countVowelStrings(33))
