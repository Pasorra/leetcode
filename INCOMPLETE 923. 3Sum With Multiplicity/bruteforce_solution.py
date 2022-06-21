class Solution:
    def threeSumMulti(self, arr: list[int], target: int) -> int:
        arr = sorted(arr)
        ans = 0
        for x in range(len(arr)):
            for y in range(x + 1, len(arr)):
                for z in arr[y + 1:]:
                    if arr[x] + arr[y] + z == target:
                        ans += 1
                    elif arr[x] + arr[y] + z > target:
                        break          
                if arr[x] + arr[y] > target:
                    break
            if arr[x] > target:
                break
        return ans
        
        
        
sol = Solution()
print(sol.threeSumMulti([2,2,1,1,3,3,4,4,5,5], 8))