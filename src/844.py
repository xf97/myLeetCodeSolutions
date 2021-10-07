class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        #保持手感，用栈就可以了
        #两分钟，一次提交，时间击败-38.24%，空间击败-5.26%
        sStack = list() #后进后出
        for i in s:
            if i == "#" and not sStack:
                #栈为空且退格
                continue
            elif i == "#":
                #退格，弹出末尾
                sStack.pop()
            else:
                sStack.append(i)
        tStack = list()
        for i in t:
            if i == "#" and not tStack:
                #栈为空且退格
                continue
            elif i == "#":
                #退格，弹出末尾
                tStack.pop()
            else:
                tStack.append(i)
        return sStack == tStack        
