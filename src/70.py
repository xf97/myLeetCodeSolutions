class Solution:
    def climbStairs(self, n: int) -> int:
        #干翻阿里
        #初级动态规划
        #n是正整数
        #三分钟，一次提交，时间击败-83.91%，空间击败-5.39%
        if n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            #不递归，直接迭代
            result = [0 for _ in range(n)]
            result[0] = 1
            result[1] = 2
            for i in range(2, n):
                result[i] = result[i - 1] + result[i - 2]
            return result[-1]
