class Solution:
    def longestValidParentheses(self, s: str) -> int:
        #干翻pdd
        #感觉要用栈，用栈来匹配括号
        #题目要求是连续的括号子串
        #要一口气匹配
        #十五分钟（其实是学习了题解后自己写的）
        #一次提交，时间击败-63.18%，空间击败-10.14%
        #边界处理
        length = len(s)
        if length < 2:
            #小于1个无法匹配
            return 0
        else:
            result = 0  #结果
            parStack = list()   #后进后出，模拟栈
            parStack.append(-1) #初始压入一个假右括号下标
            #要存储下标
            for i in range(length):
                if s[i] == "(":
                    #左括号直接压入
                    parStack.append(i)
                else:
                    #右括号，先匹配
                    parStack.pop()
                    #然后计算长度
                    if len(parStack):
                        result = max(result, i - parStack[-1])
                    else:
                        #空了，把自己压入
                        #栈中只存在一个最近一个未匹配的右括号的下标
                        parStack.append(i)
            return result
