class Solution:
    def shortestSuperstring(self, words: list) -> str:
        words = sorted(words, key=len, reverse=True)
        newWords = words.copy()
        for i, firstWord in enumerate(words):
            for secondWord in words[i + 1:]:
                if(secondWord in firstWord):
                    try:
                        newWords.remove(secondWord)
                    except ValueError:
                        continue                        
        return "".join(newWords)
            
        
        
sol = Solution()
print(sol.shortestSuperstring(["catg","ctaagt","gcta","ttca","atgcatc"]))