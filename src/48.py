class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        #干翻微软！
        #先整个垃圾的，不是原地翻转的那种
        #矩阵起码包含一行一列
        #然后螺旋翻转就可以了
        #对每一个元素
        #好好做，看了题解，用上下翻转加对角线翻转
        #原地
        #时间击败-91.32%，空间击败-80.26%
        length = len(matrix)    #n*n矩阵，长宽相等
        #先上下翻转
        #奇数行中间那行就可以不翻转
        for row in range(length // 2):
            for col  in range(length):
                matrix[row][col],  matrix[length - row - 1][col] = matrix[length - row - 1][col],  matrix[row][col]
        #print(matrix)
        #再对角线翻转，把左下翻转到右上去
        #只能翻1/2的，要不都翻回来了
        for row in range(length):
            for col in range(row):
                matrix[row][col],  matrix[col][row] = matrix[col][row],  matrix[row][col]
        '''
        length = len(matrix)
        weight = len(matrix[0])
        tempMatrix = list()
        for i in range(length):
            aRow = list()
            for i in range(weight):
                aRow.append(0)
            tempMatrix.append(aRow)
        #print(tempMatrix)
        for i  in range(length):
            for j in range(weight):
                #print(i ,j, j,  length - i - 1)
                tempMatrix[j][length -i -1] = matrix[i][j]
        #print(tempMatrix)
        matrix[:] = tempMatrix
        '''
