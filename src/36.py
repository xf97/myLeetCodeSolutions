class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        self.startPoints = [[0,0], [0,3], [0,6], [3,0], [3,3], [3,6], [6,0], [6,3], [6,6]]
        #简单方法，逐一校验每个规则，时间复杂度On2
        #result = True   #结果
        #无聊，典型的费时间题
        #一次提交，二十分钟，时间击败-45.88%，空间击败-66.60%
        if self.checkRule1(board) == False:
            return False
        if self.checkRule2(board) == False:
            return  False
        if self.checkRule3(board) == False:
            return False
        return True
    
    def checkRule1(self, _board):
        #每一行
        for row in range(9):
            aRow =  set()
            for ele  in _board[row]:
                if ele == ".":
                    continue
                elif ele not  in aRow and  int(ele) >= 1 and int(ele) <= 9:
                    aRow.add(ele)
                else:
                    return False
        return True

    def checkRule2(self, _board):
        #每一列
        for col  in range(9):
            aCol = set()
            for row in range(9):
                if _board[row][col] == ".":
                    continue
                elif _board[row][col]  not in aCol and  int(_board[row][col])  >= 1 and int( _board[row][col]) <= 9:
                    aCol.add(_board[row][col])
                else:
                    return False
        return True

    def checkRule3(self,  _board):
        #每一个小格
        for i, j in self.startPoints:
            smallGrid = set()
            for row in range(i, i + 3):
                for col in range(j, j + 3):
                    if _board[row][col] == ".":
                        continue
                    elif _board[row][col]  not in smallGrid and  int(_board[row][col])  >= 1 and  int(_board[row][col]) <= 9:
                        smallGrid.add(_board[row][col])
                    else:
                        return False
        return True

