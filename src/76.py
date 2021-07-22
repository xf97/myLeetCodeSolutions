class Solution:
    def minWindow(self, s: str, t: str) -> str:
        #字符串的最长最短这种题，可以考虑滑动窗口
        tDict = dict()
        for i in t:
            if i not in tDict:
                tDict[i] = 1
            else:
                tDict[i] += 1
        sDict = dict()
        #边界处理
        sLength = len(s)
        if sLength < len(t):
            return ""
        result = ""
        left, right = 0, 0
        ansL = -1   #用于检查是否进入过滑动窗口的标志
        while right < sLength:
            while not self.check(sDict, tDict) and right < sLength:
                if s[right] not in sDict:
                    sDict[s[right]] = 1
                else:
                    sDict[s[right]] += 1
                right += 1
            #print(right, "*")
            #直到有符合的为止
            while self.check(sDict, tDict) and left < sLength:
                #left肯定是走过right走过的路
                sDict[s[left]] -= 1
                left += 1
                ansL = left
            #print(left, "&")
            #直到不符合为止
            #记录结果
            tempResult = s[left - 1: right]
            #print(tempResult)
            if result == "":
                result = tempResult #字符串，不可变类型
            elif len(result) > len(tempResult):
                result = tempResult
            else:
                continue
        if ansL == -1:
            return result[1:]
        else:
            return result

    
    def check(self, _source, _dest) -> bool:
        '''
        _dest目标串
        _source源串
        '''
        for i in _dest:
            if i not in _source:
                return False
            elif _dest[i] > _source[i]:
                return False
        return True
