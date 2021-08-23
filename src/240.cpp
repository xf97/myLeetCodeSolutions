class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        #干翻腾讯CSIG
        #之前的代码又可以用一次
        #从右上开始搜索
        #当前元素大于目标元素，往左
        #当前元素小于目标元素，向下
        #最少一行一列
        #时间复杂度O(m+n)，空间O1
        #一次提交，十分钟，时间击败-95.95%，空间击败-45.97%
        m = len(matrix)
        n = len(matrix[0])
        row = 0
        col = n - 1
        while row < m and col >= 0:
            if  matrix[row][col] ==  target:
                return True
            elif matrix[row][col] > target:
                col -= 1
            else:
                row += 1
        return False
