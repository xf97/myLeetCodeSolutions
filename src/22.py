class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        #不用处理边界情况
        #二十分钟，一次提交，时间击败-20.66%，空间击败-47.14%
        flag = 0    #左括号空闲数量，压入一个左括号+1，压入一个右括号-1，当且仅当flag>0时才能够压入右括号
        path = ""   #某条合适路径
        remainNum = n * 2   #剩余可压入的括号数量
        result = list() #结果集
        #初始化处理
        flag += 1
        path = "("
        remainNum -= 1
        #开始向下递归
        self.generateParenthesisCore(path, result, flag, remainNum, n * 2, n - 1)
        #返回
        return result

    def generateParenthesisCore(self, _nowPath, _result, _flag, _remainNum, _totalNum, _leftNum):
        #递归终止情况
        if _remainNum == 0:
            if _nowPath not in _result:
                _result.append(_nowPath[:])
            return
        else:
            #注意回退
            #可否压入左括号
            if _flag < (_totalNum // 2) and _leftNum > 0:
                #压入左括号
                #print(_flag, _nowPath)
                _nowPath += "("
                _flag += 1
                _remainNum -= 1
                _leftNum -= 1
                self.generateParenthesisCore(_nowPath, _result, _flag, _remainNum, _totalNum, _leftNum)
                #回退状态
                _nowPath = _nowPath[:-1]
                _flag -= 1
                _remainNum += 1
                _leftNum += 1
            #可否压入右括号
            if _flag > 0:
                #print(_flag, _nowPath)
                _nowPath += ")"
                _flag -= 1
                _remainNum -= 1
                self.generateParenthesisCore(_nowPath, _result, _flag, _remainNum, _totalNum, _leftNum)
                #回退
                _nowPath = _nowPath[:-1]
                _flag += 1
                _remainNum += 1
            return
