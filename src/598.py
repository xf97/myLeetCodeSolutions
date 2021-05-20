import numpy as np

class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        #分步写，先用基础方法
        #时间复杂度应该是多个On
        #都是超时，初始化阶段就超时，就根本不允许初始化矩阵，二是要直接模拟
        #题目保证矩阵非空
        #先初始化矩阵
        #四次提交，十五分钟，脑筋急转弯呢
        #时间击败-8.26%，空间击败-5.23%
        if len(ops) == 0:
            return m * n
        #想通了，不初始化矩阵
        minRow = 40001  #40000是可能出现的最大值
        minCol = 40001
        for op in ops:
            minRow = min(op[0], minRow)
            minCol = min(op[1], minCol)
        return minRow * minCol
        '''
        matrix = list()
        for _ in range(m):
            aRow = list()
            for _ in range(n):
                aRow.append(0)
            matrix.append(aRow)
        #然后根据操作叠加
        for op in ops:
            self.add1ToMatrix(matrix, op[0], op[1])
        #然后，找到最大元素
        maxElememnt = 1 * len(ops)
        maxElememnt = -sys.maxsize - 1  #初始化为整数最小值
        for row in matrix:
            maxElememnt = max(maxElememnt, max(row))
        #最后统计出现次数
        count = 0
        for row in matrix:
            count += row.count(maxElememnt)
        return count
        '''

    #根据题目，_row和_col一定大于等1
    def add1ToMatrix(self, _matrix, _row, _col):
        for row in range(_row):
            for col in range(_col):
                _matrix[row][col] += 1
        return

