class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        #干翻拼多多
        #困难题，感觉就是要动态规划
        #不会，果断去看题解，先饶了拼多多
        #有些困难，我直接CV
        #过了过了，记住做法了
        m = len(word1)
        n = len(word2)
        #自己打一下吧
        if m * n == 0:
            return m + n
        #动态规划辅助空间
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        #初始化，当一个串为空时
        for row in range(n + 1):
            dp[row][0] = row
        for col in range(m + 1):
            dp[0][col] = col
        #开始规划
        for row in range(1, n + 1):
            for col in range(1, m + 1):
                left = dp[row][col - 1] + 1
                down = dp[row - 1][col] + 1
                leftDown = dp[row - 1][col - 1]
                if word2[row - 1] != word1[col - 1]:
                    leftDown += 1
                dp[row][col] = min(left, down, leftDown)
        return dp[n][m]
