class Solution:
    def isUgly(self, n: int) -> bool:
        #干翻蚂蚁金服
        #有2除2，有3除3，有5除5
        #边界处理
        #五分钟，两次提交，时间击败-96.10%，空间击败-20.89%
        if n == 0:
            return False
        while n % 5 == 0:
            n /= 5
        #print(n)
        while n % 3 == 0:
            n /= 3
        #print(3)
        while n % 2 == 0:
            n /= 2
        #print(2)
        return n == 1
