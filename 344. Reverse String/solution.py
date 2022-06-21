class Solution:
    def reverseString(self, s: list[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for i in range(int(len(s) / 2)):
            temp = s[i]
            s[i] = s[len(s) - i - 1]
            s[len(s) - i - 1] = temp
        return s

sol = Solution()
print(sol.reverseString(["h","e","l","l"]))