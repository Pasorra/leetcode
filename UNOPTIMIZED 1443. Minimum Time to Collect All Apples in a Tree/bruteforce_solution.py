class Solution:
    def lookBack(self, edges, count, node):
        if node == 0:
            return count
    
        for edge in edges:
            if edge[1] == node:
                if edge[3] == True:
                    count = self.lookBack(edges, count, edge[0])
                else:
                    edge[3] = True
                    count = self.lookBack(edges, count + 2, edge[0])
                break
            elif edge[0] == node:
                if edge[3] == True:
                    count = self.lookBack(edges, count, edge[1])
                else:
                    edge[3] = True
                    count = self.lookBack(edges, count + 2, edge[1])
                break
            
        return count
    
    def minTime(self, n: int, edges: list[list[int]], hasApple: list[bool]) -> int:
        for edge in edges:
            edge.append([False, False])
            if hasApple[edge[0]]:
                edge[2][0] = True
            if hasApple[edge[1]]:
                edge[2][1] = True
            edge.append(False)
        count = 0
        for edge in edges:
            if edge[2][0]:
                count += self.lookBack(edges, 0, edge[0])
            if edge[2][1]:
                count += self.lookBack(edges, 0, edge[1])
        return count
    
    
sol = Solution()
print(sol.minTime(4, [[0,2],[0,3],[1,2]], [False,True,False,False]))
            