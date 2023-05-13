class Solution:
    def corpFlightBookings(self, bookings: list[list[int]], n: int) -> list[int]:
        arr = [0 for _ in range(n + 1)]
        for first, last, seats in bookings:
            arr[first - 1] += seats
            arr[last] -= seats
        res = []
        x = 0
        for num in arr[:-1]:
            x += num
            res.append(x)
        return res


sol = Solution()
print(sol.corpFlightBookings([[1, 2, 10], [2, 3, 20], [2, 5, 25]], 5))
