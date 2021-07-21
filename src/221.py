class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        #冲，干翻字节！
        #我感觉可以用一个逐步推导的方式去做，思想是对的
        #做出来了，不过我的是max，题解的是min，现在想通了
        #二十分钟，四次提交，时间击败-87.64%，空间击败-62.34%
        #题目保证，矩阵不为空
        m = len(matrix) #行
        n = len(matrix[0])  #列
        result = list()
        _1flag = 0  #看矩阵中有没有1
        for i  in range(m):
            aList = list()
            for j in range(n):
                if matrix[i][j] == "1":
                     _1flag = 1
                aList.append(int(matrix[i][j]))
            result.append(aList)
        if m  == 1 or n == 1:
            #边界处理一下
            return _1flag
        else:
            #不至于一行或一列
            maxLength = _1flag   #最大正方形边长
            print(result)
            for  i in range(1, m):
                for j in  range(1, n):
                    #看自己的左上右三个点是否都不为0，是的话，自己这个地方的值等于他们最大的值加1
                    if result[i-1][j] != 0 and result[i][j-1] != 0 and result[i-1][j-1] != 0 and result[i][j]:
                        result[i][j] = min(result[i-1][j], result[i][j-1], result[i-1][j-1]) + 1
                        maxLength = max(maxLength, result[i][j])
                    else:
                        continue
            print(result)
            return maxLength **2
