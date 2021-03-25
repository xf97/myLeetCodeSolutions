class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        #半小时，看看能不能做出来中等题
        #举个例子想一想
        #循环条件：pop序列没完
        #只有当栈顶元素等于pop时，栈元素才出栈，否则，就压入push的元素
        #直到push压到一个与pop相等的，那么pop后移，否则push完但是pop没完返回false
        #只有当push和pop都完了才返回true
        #题目保证，pushed和poped的长度相等，但是可能为0
        #两次过，不过只用了22分钟
        #时间击败：41.66%，空间击败：37.52%
        if len(pushed) == 0:
            return True
        else:
            simulationStack = list()    #模拟栈，尾部是栈顶
            #首先压入一个元素，不可能不压入元素就pop吧
            simulationStack.append(pushed[0])   #pushed长度肯定大于1
            pushed.pop(0)
            while len(popped) > 0:
                #首先判断栈顶元素是否与popped首元素相等
                #栈空先压栈
                if len(simulationStack) == 0:
                    simulationStack.append(pushed[0])
                    pushed.pop(0)
                if popped[0] == simulationStack[-1]:
                    #出栈
                    simulationStack.pop()
                    popped.pop(0)
                else:
                    #不等于，一直压栈，直到等于
                    #要注意压栈压完了但是出栈还没完的情况
                    while simulationStack[-1] != popped[0] and len(pushed) > 0:
                        simulationStack.append(pushed[0])
                        pushed.pop(0)
                    #压完都找不到
                    if simulationStack[-1] != popped[0] and len(pushed) == 0:
                        return False
            return len(pushed) == 0 and len(popped) == 0
