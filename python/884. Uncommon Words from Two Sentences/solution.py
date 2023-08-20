class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> list[str]:
        s3 = s1 + " " + s2
        s3 = s3.split(" ")
        dic = dict()
        for s in s3:
            try:
                dic[s] += 1
            except:
                dic[s] = 1
        result = []
        for key, val in dic.items():
            if val == 1:
                result.append(key)
        return result