class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        #????看到这个对角线我人都懵了
        #移动顺序我基本看懂了
        #两个方向，m行n列的话
        #一、m--, n++，触到边界右下转向
        #二、m++, n--，触到边界下右转向
        #初始时是第一个方向
        #有个疑问，数组会为空吗—— 不会
        #干翻阿里巴巴！
        #看了题解，用模拟真的太亏了
        #还是题解的有意思，先遍历对角线，然后反转
        #二十分钟，两次提交，时间击败-93.90%，空间击败-50.13%
        result = list()
        m = len(mat)    #m行n列
        n = len(mat[0])
        #第一行和最后一列都是对角线起点
        flag = 0
        #奇数行翻转
        for i in range(n):
            row = 0
            col = i     #起点
            aCrossLine = list()
            while row < m and col >= 0:
                aCrossLine.append(mat[row][col])
                row += 1
                col -= 1
            flag += 1
            #翻转
            if flag % 2 == 1:
                #奇数
                aCrossLine.reverse()
            result.extend(aCrossLine)
        #最后一列
        #跳过第一个元素的交际
        for i in range(1, m):
            col = n - 1
            row = i
            aCrossLine = list()
            while row < m and col >= 0:
                aCrossLine.append(mat[row][col])
                row += 1
                col -= 1
            flag += 1
            #翻转
            if flag % 2 == 1:
                #奇数
                aCrossLine.reverse()
            result.extend(aCrossLine)
        return result
        '''
        flag = 0    #方向
        #开始
        while len(result) < (m * n):
            #当前元素进入
            print(row, col)
            result.append(mat[row][col])
            #然后对角线加边界判断
            if flag == 0: 
                #方向1
                if row - 1 >= 0 and col + 1 < n:
                    #没达到边界条件
                    row -= 1
                    col += 1
                else:
                    #转向
                    #右边有吗
                    if col + 1 < n:
                        col += 1
                        flag = 1 if flag == 0 else 0
                    #要不然就往下
                    else:
                        row += 1
                        flag = 1 if flag == 0 else 0
            else:
                #方向2
                if row + 1 < m and col - 1 >= 0:
                    #没到边界
                    row += 1
                    col -= 1
                else:
                    #转向
                    #下有吗
                    if row + 1 < m:
                        row += 1
                        flag = 1 if flag == 0 else 0
                    else:
                        #不行就去右边
                        col += 1
                        flga = 1 if flag == 0 else 0
        return result
        '''
