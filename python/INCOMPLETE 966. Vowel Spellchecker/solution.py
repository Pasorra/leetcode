class Solution:
    def spellchecker(self, wordlist: list[str], queries: list[str]) -> list[str]:
        wordlistWithoutVowels = []
        answer = []
        for word in wordlist:
            wordlistWithoutVowels.append("".join([x for x in word if x not in ['a', 'e', 'i', 'o', 'u']]))
        for query in queries:
            wasAdded = False
            for word in wordlist:
                if word == query:
                    if wasAdded:
                        answer.pop()
                    answer.append(word)
                    wasAdded = True
                    break
                if not wasAdded and word.lower == query.lower:
                    answer.append(query)
                    wasAdded = True
            if not wasAdded:
                newQuery = "".join([x for x in word if x not in ['a', 'e', 'i', 'o', 'u']])
                
            


sol = Solution()

print(sol.spellchecker(["KiTe","kite","hare","Hare"], ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]))