class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed((s.split())))
    
sol = Solution()
print(sol.reverseWords("Hello   world"))