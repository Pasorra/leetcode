class Solution:
    def addDigits(self, num: int) -> int:
        while num > 9:
            acc = 0
            for i in str(num):
                acc += int(i)
            num = acc
        return num