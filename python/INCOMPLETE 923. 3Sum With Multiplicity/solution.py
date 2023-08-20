class Solution:
    def recursivelySolve(self, index, iterLeft, val, newArr, target, fedInNumbers, result = 0):
        secondVal = int(newArr[index][0])
        if iterLeft == 1 and secondVal + val == target:
            result += 1
        elif secondVal + val > target:
            return result
        
        
    
    def threeSumMulti(self, arr: list[int], target: int) -> int:
        #Organize
        dic = dict()
        arr.sort()
        for i in arr:
            try:
                dic[i] += 1
            except:
                dic[i] = 1
        newArr = []
        for key in dic:
            newArr.append(f"{key}:{dic[key]}")
        
        #Calcualte
        res = 0
        for i in range(len(newArr)):
            if int(newArr[i][1]) > 1:
                res += self.recursivelySolve(i + 1, 1, int(newArr[i][0]) * 2, newArr, target, [i, i])
            
                    
        return 0
        
        
        
sol = Solution()
print(sol.threeSumMulti([1,1,1,1,1,1,1,1], 1))