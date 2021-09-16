class Solution:
    def simplifyPath(self, path: str) -> str:
        #用一个类似栈的处理方法
        #逐个检查
        #先切分
        #三十五分钟，四次提交，时间击败-63.44%，空间击败-90.84%
        stack = list()
        dirs = path.split("/")
        #print(dirs)
        for d in dirs:
            if d == "." or d == '':
                continue
            elif d == "..":
                if stack:
                    stack.pop(-1)
            else:
                stack.append(d)
        #print(stack)
        return "/" + "/".join(stack) if "/" + "/".join(stack) != "" else "/"

        '''
        length = len(path)
        stack = list()  #模拟栈，后进后出
        index = 0
        while index < length:
            #print(stack)
            if path[index] == "/":
                #向下找连续的/
                nex = index + 1
                while nex < length and path[nex] == "/":
                    nex += 1
                #压入一个/
                if stack and stack[-1] != "/" or not stack:
                    stack.append("/")
                index = nex
            elif path[index] == ".":
                nex = index + 1
                if nex < length and path[nex] != ".":
                    #本级目录，没什么用
                    stack.pop()
                    index += 1
                elif nex < length and path[nex] == ".":
                    after = nex + 1
                    if after < length and path[after] != "/":
                        while after < length and path[after] != "/":
                            after += 1
                        #这是目录
                        stack.append(path[index: after])
                        index = after
                    else:
                        #父目录，弹出上一级目录
                        #print(stack, path[index], path[nex])
                        count = 2
                        while stack and count:
                            stack.pop(-1)
                            count -= 1
                        index = after
                else:
                    index = nex
            else:
                #就是目录名
                nex = index + 1
                while nex < length and path[nex] != "/":
                    nex += 1
                stack.append(path[index:nex])
                index = nex
        #末尾处理
        if stack[-1] == "/" and len(stack) > 1:
            stack.pop()
        #print(stack)
        return "".join(stack)
        '''
