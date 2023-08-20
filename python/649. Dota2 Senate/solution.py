class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        i = 0
        arr = list(senate)
        while True:
            currentVote = arr[i]
            if(currentVote == "R"):
                if("D" not in arr):
                    return "Radiant"
                try: 
                    del arr[i + arr[i:].index("D")]
                except:
                    del arr[arr.index("D")]
            elif(currentVote == "D"):
                if("R" not in arr):
                    return "Dire"
                try:
                    del arr[i + arr[i:].index("R")]
                except:
                    del arr[arr.index("R")]
            i += 1
            if(i >= len(arr)):
                i = 0
        
        
sol = Solution
print(sol.predictPartyVictory(sol, "RDD"))
                