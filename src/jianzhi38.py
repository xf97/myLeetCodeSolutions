class Solution:
    def permutation(self, s: str) -> List[str]:
        #这个题我是做过的，逐级向下，每次缩减一个，直至最后只剩一个
        #51/52，超时，方法没有问题，就是没有针对重复元素
        #三次提交，三十分钟，时间击败-70.91%，空间击败-98.90%
        if len(s) == 1:
            return [s]
        else:
            result = list() #结果
            listStr = list(s)
            #listStr.sort()
            self.getAllStr(result, listStr, "")
            return  result
    
    def getAllStr(self,  _result, _nowStr, _nowResult):
        if  len(_nowStr) == 1:
            '''
            aResult  = _nowResult +  _nowStr[0]
            #if aResult not in _result:
            '''
            _result.append(_nowResult +  _nowStr[0])
            return
        else:
            #str是不可变类型，担心拷贝出现问题
            tempStr = _nowStr[:]
            #tempResult = _nowResult[:]
            dic = set() #不重复选择元素
            for c in _nowStr:
                if c in dic:
                    continue
                dic.add(c)
                tempResult = _nowResult[:] + c
                tempStr.remove(c)
                #print(tempStr, tempResult)
                self.getAllStr(_result, tempStr,  tempResult)
                tempStr.append(c)
                tempResult = _nowResult[:]
            return
