class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        #要把打印函数和驱动函数分开
        #起码要有两行两列，否则直接打印就行了
        #这题还是难的，应该做个中等题
        #覆盖完特殊情况后一遍就过了
        #时间击败：92.57%，空间击败：23.02%
        rows = len(matrix)  #行
        cols = 0    
        if rows > 0:
            cols = len(matrix[0])   #列
        if rows == 0 or cols == 0:
            #没有元素
            return list()
        printNumList = list()   #要打印的元素顺序
        start = 0   #起点，从左上角对角线开始打印
        while start * 2 < rows and start * 2 < cols:
            #确定起点和打印边界，开始打印
            self.get1Circle(start, matrix, rows, cols, printNumList)
            start += 1
        return printNumList

    def get1Circle(self, _start, _matrix, _rows, _cols, _numList):
        #圆是对称的，现在有左上，来算一下右下
        endCol = _cols - _start - 1
        endRow =  _rows - _start - 1
        #然后再顺时针打印每一行或列
        #注意，不重复打印上一行列的末尾
        #向右
        for col in range(_start, endCol + 1):
            _numList.append(_matrix[_start][col])
        #向下，向下要先确定有多行
        if endRow != _start:
            #print("down")
            for row in range(_start + 1, endRow + 1):
                _numList.append(_matrix[row][endCol])
        #向左，向左要确定有多列和多行
        if endCol != _start and endRow != _start:
            #print("left")
            for col in range(endCol - 1, _start - 1, -1):
                _numList.append(_matrix[endRow][col])
        #向上，要确定有多行
        #不覆盖起点
        if endRow != _start and endCol != _start:
            #print("up")
            for row in range(endRow - 1, _start, -1):
                _numList.append(_matrix[row][_start]);
        return
