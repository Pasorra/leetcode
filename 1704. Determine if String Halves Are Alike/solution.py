class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = ["a", "e", "i", "o", "u"]
        count = 0
        s1 = s[:int(len(s)/2)].lower()
        s2 = s[int(len(s)/2):].lower()
        for i in s1:
            if i in vowels:
                count += 1
        for i in s2:
            if i in vowels:
                count -= 1
            if count < 0:
                return False
        return count == 0


sol = Solution()
print(sol.halvesAreAlike("boookkok"))