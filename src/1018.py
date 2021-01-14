class Solution:
    '''
    我又回来啦
    time defeat: 17.11%
    space defeat: 23.51%
    time consuming: less than 15 mins
    '''
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        #总体思想，逐个读取，二进制转十进制，然后判断能够整除
        resultList = list() #结果数组
        num = str() #当前二进制字符串、
        #开始遍历
        for i in A:
            #使用字符串完成拼接
            num += str(i)
            #然后二进制转十进制
            if int(num, base = 2) % 5 ==  0:
                #可以整除，记录结果
                resultList.append(True)
            else:
                resultList.append(False)
        #返回结果
        return resultList