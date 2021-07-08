class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        #想到了，先遍历一遍，记录所有要置零的行和列
        #额外空间，O(m+n)，时间O(mn)
        #十分钟，一次提交，时间击败-100%，空间击败-64.35%
        rowSet =  set()
        colSet = set()
        length = len(matrix)
        weight = len(matrix[0])
        for  row in range(length):
            for col in range(weight):
                if matrix[row][col] == 0:
                    rowSet.add(row)
                    colSet.add(col)
                else:
                    continue
        #print(rowSet)
        #print(colSet)
        #然后，置零每一行和列
        for row in rowSet:
            for col in range(weight):
                matrix[row][col] =  0
        for col in colSet:
            for row in  range(length):
                matrix[row][col] = 0
        return

