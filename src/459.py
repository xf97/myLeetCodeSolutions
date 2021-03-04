class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        '''
        time defeat: 40.58%
        space defeat: 58.48%
        '''
        #一开始想到的是最简单的，暴力遍历
        result = False  #结果
        for index in range(1, (len(s) // 2) + 1 ):
            #只用遍历一半就行
            #拼接字符串
            subStr = s[0: index]
            #print(subStr)
            if subStr * (len(s) // index) == s:
                result = True
                break
            else:
                continue
        return result
