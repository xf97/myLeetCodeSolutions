class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        #正整数，需要求出这个数的所有因子
        #因素不包含自身
        #两次提交，十分钟，时间击败：96.25%，空间击败：99.61%
        if num == 1:
            return False
        factorList = list() #因子列表
        factorList.append(1)    #压入1，从2开始可以不包含本身
        for i in range(2, int(num ** 0.5 + 1)):
            #i开始除
            if num % i == 0:
                #可以整除
                factorList.append(i)
                factorList.append(num // i)
            else:
                continue
        return sum(factorList) == num
