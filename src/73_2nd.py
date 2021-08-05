class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        #避免覆盖的话，先用一个m+n的额外空间好了
        #干翻蚂蚁金服
        #自己做的，一次提交
        #时间击败-68.43%，空间击败-57.71%
        #m, n最小为1
        m = len(matrix)
        n = len(matrix[0])
        ZeroLines = [0] * (m + n)
        #为1表示需要清零，否则不需要
        #前m个表示行
        #后n个表示列
        #第i列应该是m + i - 1
        for row in range(m):
            for col in range(n):
                if matrix[row][col] == 0:
                    ZeroLines[row] = 1  #row绝对存在
                    ZeroLines[m + col] = 1
                else:
                    continue
        #print(ZeroLines)
        #然后置空
        #先置空行
        for row in range(m):
            if ZeroLines[row]:
                #为1
                #print(row, "***")
                for col in range(n):
                    matrix[row][col] = 0
            else:
                continue
        #然后置空列
        for col in range(m, m + n):
            if ZeroLines[col]:
                #print(col - m, ")))")
                for row in range(m):
                    matrix[row][col - m] = 0
            else:
                continue
        return
