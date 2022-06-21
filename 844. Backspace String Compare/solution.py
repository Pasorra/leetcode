class Solution:
    def CheckWordAndReplace(self, word: str) -> str:
        length = len(word)
        i = 0
        while True:
            if(i == length):
                return word
            if(word[i] == "#"):
                if(i != 0):
                    word = word.replace( word[i-1] + word[i], "", 1)
                    i -= 1
                    length -= 2
                    continue
                else:
                    word = word.replace(word[i], "", 1)
                    length -= 1
                    continue
            i += 1       
            
    def backspaceCompare(self, s: str, t: str) -> bool:
        s = Solution.CheckWordAndReplace(self, s)
        t = Solution.CheckWordAndReplace(self, t)
        return s == t
        
    
sol = Solution
print(sol.backspaceCompare(sol, "a##c", "#a#c"))