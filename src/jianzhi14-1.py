class Solution:
    def cuttingRope(self, n: int) -> int:
        #基础的动态规划题，我又来亵渎中等题目了
        #从上到下分析问题，从下到上解决问题
        #48%, 11%, 亵渎动态规划完成
        if n < 2:
            return 0
        elif n == 2:
            return 1
        elif n == 3:
            return 2
        else:
            cutInI = [0] * (n + 1)    #在I处剪一刀的最大值
            cutInI[1] = 1
            cutInI[2] = 2
            cutInI[3] = 3
            #从短绳向长绳子去求
            for i in range(4, n + 1):
                result = 0
                #在绳子的长度一定的情况下，去计算最大乘积
                for j in range(1, i // 2 + 1):
                    product = cutInI[j] * cutInI[i - j]
                    result = max(product, result)
                    cutInI[i] = result
            return cutInI[-1]
