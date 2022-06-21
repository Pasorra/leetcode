class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        newS = [x for x in s]
        foundVowels = []
        for i in s:
            if i in vowels:
                foundVowels.append(i)
        foundVowels = list(reversed(foundVowels))
        index = 0
        for i, _ in enumerate(newS):
            if newS[i] in vowels:
                newS[i] = foundVowels[index]
                index += 1
        
        return "".join(newS)
    
    
sol = Solution()
print(sol.reverseVowels("Hello"))