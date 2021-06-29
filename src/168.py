class Solution:
    def convertToTitle(self, columnNumber: int) -> str:、
        #一次提交，五分钟，时间击败-81.14%，空间击败-5.46%
        def  getAlpha(_index):
            #返回字母
            return chr(ord("A") + _index)
        result = "" #结果
        while columnNumber:
            #index = (columnNumber % 27)
            columnNumber -=  1  #10进制转[1,26]进制，因为没有0所以减1
            index = columnNumber % 26   #计算偏移量
            result += getAlpha(index)   #拼接
            columnNumber //=  26    #进入下一循环 
        return result[::-1] #翻转
