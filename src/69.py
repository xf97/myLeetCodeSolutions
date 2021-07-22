class Solution:
    def mySqrt(self, x: int) -> int:
        #干翻字节！这个简单题如果不用库函数感觉就不简单了
        #我可以通过由下到上的遍历解决这个问题
        #x非负，平方根自然非负
        #时间复杂度O(n1/2)，空间复杂度O1
        #三分钟，一次提交，时间击败-5.02%，空间击败-56.00%
        result = 0  
        while (result * result) <= x and ((result + 1) * (result + 1)) <= x:
            result += 1
        return result
