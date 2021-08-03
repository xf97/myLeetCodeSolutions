class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        #这个还是可以干翻的
        #干翻蚂蚁金服！
        #简单动态规划
        #第i,j个
        #递归公式 f(i,j) = min(f(i-1,j), f(i,j-1)) + grid[i,j]
        #包含非负整数，一定加
        #要初始化第一行和第一列
        #六分钟，一次提交，时间击败-98.57%，空间击败-57.03%
        m = len(grid)   #行
        n = len(grid[0])    #列
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = grid[0][0]
        #第一行
        for i in range(1, n):
            dp[0][i] = dp[0][i - 1] + grid[0][i]
        #第一列
        for j in range(1, m):
            dp[j][0] = dp[j - 1][0] + grid[j][0]
        #开始推
        for row in range(1, m):
            for col in range(1, n):
                dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + grid[row][col]
        return dp[m - 1][n - 1]
