class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        #终于来个带劲点的了
        #干翻蚂蚁金服！
        #动态规划，计算以每个点位作为右下角的正方形的最大边长
        #然后把非1的加起来就行
        #题目保证矩阵非空
        #很棒，十五分钟，一次提交
        #时间击败-93.91%，空间击败-9.27%
        m = len(matrix) #m行
        n = len(matrix[0])  #n列
        #初始化第一行和第一列
        dp = [[0] * n for _ in range(m)]
        #第一行和第一列跟matrix一样
        for i in range(n):
            dp[0][i] = matrix[0][i]
        for j in range(m):
            dp[j][0] = matrix[j][0]
        #然后开始递推
        for row in range(1, m):
            for col in range(1, n):
                if matrix[row][col]:
                    #首先兄弟这里得不为0
                    #只有当兄弟左、左上、上三个方格都有东西的时候，兄弟这里才有东西
                    dp[row][col] = min(dp[row - 1][col], dp[row - 1][col - 1], dp[row][col - 1]) + 1
                else:
                    dp[row][col] = 0
        #弄好了，然后遍历，加起来
        result = 0
        for row in range(m):
            for col in range(n):
                result += dp[row][col]
        return result
