class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        #基础思路：
        #1. 先收集所有非破折号字符（小写到大写）
        #2. 然后整除求余，把前余数个单独放置
        #3. 破折号连接
        '''
        通过
        time defeat: 39.66%
        space defeat: 47.12%
        '''
        poZheHaoStr = "-"   #破折号
        validStr = str()    #有效符号组成的字符串
        for i in S:
            if i.isalpha():
                #是字母，直接转成大写
                validStr += i.upper()
            elif i.isdigit():
                #是数字，加入
                validStr += i
            else:
                #破折号，不要
                continue
        #开始取余，然后分组
        strList = list()    #用于保存分组后的字符串
        preStrNum = len(validStr) % K
        if preStrNum:
            strList.append(validStr[:preStrNum])
            validStr = validStr[preStrNum:]
        #按K步长截断
        i = 0
        while i < len(validStr):
            strList.append(validStr[i : i + K])
            i += K
        #最后拼接返回
        result = str()
        #print(strList)
        for (index, i) in enumerate(strList):
            result += i
            if index != len(strList) - 1:
                result += poZheHaoStr
        return result
