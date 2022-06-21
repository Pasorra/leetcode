class Solution:
    def firstCheck(self, board):
        anyChange = False
        while True:
            changed = False
            for y in range(9):
                for x in range(9):
                    print(board[y][x] + " ", end="")
                    if board[y][x] == "." or len(board[y][x]) > 1:
                        nums = self.checkCol(board,x)
                        nums = self.checkRow(board,y,nums)
                        nums = self.checkBox(board, x, y, nums)
                        if(board[y][x] != "".join(nums)):
                            changed = True
                            anyChange = True
                            board[y][x] = "".join(nums)
                print()
            if not changed:
                break
        return (board, anyChange) 
    
    def secondCheck(self, board):
        anyChange = False
        while True:
            changed = False
            for y in range(9):
                for x in range(9):
                    print(board[y][x] + " ", end="")
                    if board[y][x] == "." or len(board[y][x]) > 1:
                        nums = self.checkCol(board,x)
                        nums = self.checkRow(board,y,nums)
                        nums = self.checkBox(board, x, y, nums)
                        if(board[y][x] != "".join(nums)):
                            changed = True
                            anyChange = True
                            board[y][x] = "".join(nums)
                print()
            if not changed:
                break
        return (board, anyChange) 
    
    def checkCol(self, board, xPos):
        nums = [str(x + 1) for x in range(9)]
        for y in range(9):
            if board[y][xPos] in nums:
                nums.remove(board[y][xPos])
        return nums
    
    def checkUniqueInCol(self, board, xPos, yPos):
        for y in range(9):
            if board[y][xpo] and board[y][xPos] :
                nums.remove(board[y][xPos])
        return nums
    
    def checkRow(self, board, yPos, nums: list[str]):
        for x in range(9):
            if board[yPos][x] in nums:
                nums.remove(board[yPos][x])
        return nums
    
    def checkBox(self, board, xPos, yPos, nums: list[str]):
        boxX = int(xPos/3)
        boxY = int(yPos/3)
        for y in range(boxY * 3, (boxY * 3) + 3):
            for x in range(boxX * 3, (boxX * 3) + 3):
                if board[y][x] in nums:
                    nums.remove(board[y][x])
        return nums         

    def solveSudoku(self, board: list[list[str]]) -> None:
        while True:
            board, firstChange = self.firstCheck(board)
            board, secondChange = self.secondCheck(board)
            if not firstChange and not secondChange:
                break
        
sol = Solution()
print(sol.solveSudoku([[".",".","9","7","4","8",".",".","."],["7",".",".",".",".",".",".",".","."],[".","2",".","1",".","9",".",".","."],[".",".","7",".",".",".","2","4","."],[".","6","4",".","1",".","5","9","."],[".","9","8",".",".",".","3",".","."],[".",".",".","8",".","3",".","2","."],[".",".",".",".",".",".",".",".","6"],[".",".",".","2","7","5","9",".","."]]))