class Solution:
    def printNumbers(self, n: int) -> List[int]:
        #虽然知道全排列的方法，但还是先练习用字符串表示的方法
        #完成，时间击败：5.23%，空间击败：22.22%
        #python3
        if n <= 0:
            return list()
        resultList = list() #结果
        numStr = "0" * n    #暂存数字
        maxStr = "9" * n    #最大数字
        #开始打印现在，注意，每一位从1开始打印
        numStr = self.increaseNum(numStr, maxStr)
        while numStr != "-1":
            #print(numStr, maxStr)
            resultList.append(int(numStr))
            numStr = self.increaseNum(numStr, maxStr)
        return resultList

    def increaseNum(self, _nowNum, _maxNum):
        #当_nowNum == _maxNum时返回false
        if _nowNum == _maxNum:
            return "-1"
        else:
            #其他时候，返回true，并且将_nowNum自增1
            takeOver = 0    #进位符号
            #从后向前，加1进位
            #print(_nowNum, " ", end = " ")
            for i in range(len(_nowNum) - 1, -1, -1):
                #print(_nowNum[i], takeOver, end = " ")
                nSum = int(_nowNum[i]) + takeOver   #加上进位
                takeOver = 0
                if i == len(_nowNum) - 1:
                    nSum += 1
                #判断是否继续向前进位
                if nSum < 10:
                    _nowNum = _nowNum[:i] + str(nSum) + _nowNum[i + 1:] #直接修改原数字
                    break
                else:
                    takeOver = 1
                    nSum -= 10
                    _nowNum = _nowNum[:i] + str(nSum) + _nowNum[i + 1:]
            #print(_nowNum)
            return _nowNum
