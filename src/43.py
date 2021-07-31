class Solution:
    '''
    很好，虽然麻烦，但是自己做出来了
    一次提交，二十分钟，时间击败-19.80%，空间击败-22.03%
    '''
    def mulStr(self, _num1, _num2, _weight):
        carry = 0   #进位
        result = str()
        for i in _num2[::-1]:
            aResult = int(_num1) * int(i) + carry
            carry = aResult // 10
            aResult %= 10
            result += str(aResult)
        #如果末尾还有进位呢
        if carry:
            result += str(carry)
        result = result[::-1]
        while _weight != 1:
            result += "0"
            _weight //= 10
        return result

    def addStr(self, _num1, _num2):
        carry = 0   #进位
        #_num1是小的那个
        if len(_num1) > len(_num2):
            _num1, _num2 = _num2, _num1
        result = ""
        index = 1
        for i, j in zip(_num1[::-1], _num2[::-1]):
            aResult = int(i) + int(j) + carry
            carry = aResult // 10
            aResult %= 10
            result += str(aResult)
            index += 1
        #print(result)
        #处理长的这一段
        for j in _num2[index * (-1)::-1]:
            #print(j)
            aResult = int(j) + carry
            carry = aResult // 10
            aResult %= 10
            result += str(aResult)
        #print(result)
        #如果末尾还有进位
        if carry:
            result += str(carry)
        #print(result, _num1, _num2)
        return result[::-1]

    def multiply(self, num1: str, num2: str) -> str:
        #干翻拼多多
        #想拆分，拆成
        #一个字符串与一个字符的乘法
        #然后多个字符串的加法
        result = "0"
        #边界条件
        if num1 == "0" or num2 == "0":
            return "0"
        #num1保证是短的数字
        if len(num1) > len(num2):
            num1, num2 = num2, num1
        #然后逐个乘法，保存乘积
        mulResult = list()
        weight = 1
        for i in num1[::-1]:
            mulResult.append(self.mulStr(i, num2, weight))
            weight *= 10
        #print(mulResult)
        #然后再加起来
        for num in mulResult:
            result = self.addStr(result, num)
            #print(result)
        return result
