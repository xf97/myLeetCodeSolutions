class Solution:
    def myPow(self, x: float, n: int) -> float:
        #数学不太行，要我就要舔了
        #干翻腾讯CSIG
        #直接耍赖
        #return x ** n
        #递归向下
        #五分钟，一次提交，时间击败-99.02%，空间击败-5.36%
        def quickPow(n):
            #递归边界
            if n == 0:
                return 1.0
            #计算自己的一般
            y = quickPow(n // 2)
            #判断n是整数还是奇数
            return y * y if n % 2 == 0 else y * y * x   #多乘一个x
        #注意正数负数
        return quickPow(n) if n >= 0 else 1.0 / quickPow(-1 * n)
            
