class Solution:
    def fib(self, n: int) -> int:
        #用递归做一下
        #超时，递归，20/51
        '''
        if n == 0:
            return 0
        elif n == 1:
            return 1
        else:
            return self.fib(n - 1) + self.fib(n - 2)
        '''
        #从f(0)和f(1)开始计算
        #边界情况
        '''
        time defeat: 11.48%
        space defeat: 89.22%
        '''
        if n == 0 or n == 1:
            return n
        else:
            #保留之前计算的两个数，层层向后
            (num1, num2) = (0, 1)   #num1是小的那个，num2是大的那个
            result = 0  #结果
            for i in range(2, n + 1):
                #print(num1, num2)
                result = (num1 + num2) % 1000000007
                num1 = num2
                num2 = result
            return result
        
