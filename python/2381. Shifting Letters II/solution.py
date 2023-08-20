# import numpy as np


class Solution:
    # def shiftingLetters(self, s: str, shifts: list[list[int]]) -> str:
    #     s = np.array([ord(x) - 97 for x in s])
    #     for shift in shifts:
    #         print(s[shift[0]: shift[1]])
    #         s[shift[0]: shift[1] + 1] += 1 if shift[2] == 1 else -1
    #     s = np.remainder(s, 26)
    #     s[:] += 97
    #     return "".join([chr(x) for x in s])

    def shiftingLetters(self, s: str, shifts: list[list[int]]) -> str:
        s = [x for x in s]
        arr = [0] * (len(s) + 1)
        for start, end, dir in shifts:
            if dir == 1:
                arr[start] += 1
                arr[end + 1] -= 1
            else:
                arr[start] -= 1
                arr[end + 1] += 1
        add = 0
        for i, num in enumerate(arr[:-1]):
            add += num
            char = s[i]
            s[i] = chr((((ord(char) - 97 + add) % 26)) + 97)
        return "".join(s)


sol = Solution()
print(sol.shiftingLetters("abc", [[0, 1, 0], [1, 2, 1], [0, 2, 1]]))
