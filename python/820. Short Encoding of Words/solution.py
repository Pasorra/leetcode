class Solution:
    def minimumLengthEncoding(self, words: list[str]) -> int:
        words = sorted(words, key=len, reverse=True)
        shouldSkip = []
        for i in range(len(words)):
            sliced = words[i + 1:len(words)]
            for x, word in enumerate(sliced):
                if (i + x + 1) in shouldSkip:
                    continue
                length = len(words[i]) - len(word)
                if words[i][length:] == word:
                    shouldSkip.append((x + i + 1))
        count = 0
        for i in range(len(words)):
            if i in shouldSkip:
                continue
            count += len(words[i]) + 1
        return count


sol = Solution()
print(sol.minimumLengthEncoding(["t"]))
