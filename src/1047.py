class Solution:
    def removeDuplicates(self, S: str) -> str:
        #简单题我要重拳出击了
        '''
        学会思考用新的数据结构的一天（尽管程序效率一般但是一次提交就通过!）
        time defeat: 5.06%
        space defeat: 31.34%
        '''
        #边界条件
        if not S:
            return S
        else:
            '''
            #普适情况
            #能否用栈来实现？
            #使用list来模拟栈
            stackList = list()
            #遍历整个字符串
            for i in S:
                #空栈时，压入
                if len(stackList) == 0:
                    #在头部添加，头部时栈顶
                    stackList.insert(0, i)
                else:
                    #非空栈，要判断当前元素和已有栈顶元素是否相同
                    if i == stackList[0]:
                        #相同，栈顶元素出战，两个元素一起被抛弃
                        stackList.pop(0)
                    else:
                        #不相同，接着压入
                        stackList.insert(0, i)
            #最后，从底向顶遍历栈，重组字符串，返回去
            result = str()
            for i in stackList[::-1]:
                result += i
            return result
            '''
            #改一下代码优化一下效率
            #把队尾定义成栈顶不就可以不逆序了
            '''
            搞定
            time defeat: 91.27%
            space defeat: 15.26%
            '''
            stackList = list()
            for ch in S:
                #只有在非空栈，且栈顶元素和现在元素相等时，才出栈
                if stackList and ch == stackList[-1]:
                    stackList.pop()
                else:
                    #统一在队尾进行操作
                    stackList.append(ch)
            return "".join(stackList)
