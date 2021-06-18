class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        #今天第二次玷污中等题，有点像全排列映射的感觉
        #数字是2-9范围内  
        #二十分钟，一次提交，差点超时，时间击败-6.69%，空间击败-12.79%
        #不过也算是自己做出来的中等题了
        numAndAlpha = ["", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        #边界情况
        result = list() #结果
        if len(digits) == 0:
            return result
        else:
            candidate = list()
            for i in  digits:
                candidate.append(numAndAlpha[int(i) - 1])
            #print(candidate)
            #然后，由前向后，要递归，因为不知道有几层循环 
            #初始化
            for i in candidate[0]:
                result.append(i)
            #开始向下 
            self.getResult(candidate,  1,  result)
            return result

    def getResult(self, _candidateList,  _index, _result):
        if _index == len(_candidateList):
            #循环结束
            return
        else:
            #加到结果中 
            _resultCopy  = _result[:]
            for r in _resultCopy:
                for c in _candidateList[_index]:
                    rCopy = r[:]
                    rCopy += c
                    _result.append(rCopy)
                _result.remove(r)
            return  self.getResult(_candidateList, _index  + 1, _result)
