class Solution:
    def cuttingRope(self, n: int) -> int:
        #想用python3写一下
        #怎么感觉跟上一题一样
        #不对，这一题n的上限大了很多
        #懂了，一个让我用动态规划一个让我用贪婪
        #我先用动态规划做一下吧，注意结果取模
        #题目规定，n >= 2
        #很好，动态规划的代码没有忘记
        '''
        if n == 2:
            return 1
        elif n == 3:
            return 2
        else:
            #动态规划，从下往上，记录已有的数据
            productList = [0] * (n + 1) #这个列表记录了在i处切一刀的最大乘积
            #先记录一些小的
            productList[1] = 1
            productList[2] = 2
            productList[3] = 3
            #然后去计算4到n的
            for i in range(4, n + 1):
                tempMax = 0 #长度为i的绳子的最大成绩
                #注意0不能切
                for j in range(1, i // 2 + 1):
                    tempMax = max(tempMax, productList[j] * productList[i - j])
                productList[i] = tempMax
            #然后，返回结果
            return productList[-1]
            '''
            #现在来做贪婪的，有3切3，没3切2
            #数学证明的，在大于5的时候
            #时间击败：88.41%，空间击败：58.62%
        if n == 2:
            return 1
        elif n == 3:
            return 2
        else:
            #在大于等于4的时候，就切3，否则就切2
            timeOf3 = n // 3
            #要注意为4的情况，为4取2更大
            if n - (timeOf3 * 3) == 1:
                timeOf3 -= 1
            timeOf2 = (n - timeOf3 * 3) // 2
            return int(3 ** timeOf3) * int(2 ** timeOf2) % 1000000007
