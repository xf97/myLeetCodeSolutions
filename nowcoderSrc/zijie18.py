'''
这是入门题，但是我读题目就不像入门题
开始吧
先把主体程序打好
牛客的调试体验真的很差
'''

#感觉这里可以递归处理
#别递归，递归搞毛，递归会失去前面的信息
def checkStr(_str) -> str:
    rightStr = list()
    for c in _str:
        if  len(rightStr) < 3:
            rightStr.append(c)
        else:
            rightStr.append(c)
            #检查尾部
            if rightStr[-3] == rightStr[-2] == rightStr[-1]:
                #python支持连续判断
                #rightStr.append(c)
                rightStr.pop()
            elif len(rightStr) >= 4 and rightStr[-4] == rightStr[-3] and rightStr[-2] ==  rightStr[-1]:
                #rightStr.append(c)
                rightStr.pop()
            else:
                #rightStr.append(c)
                pass
    return "".join(rightStr)
    '''
    #小于3长度的字符串一定是正确地
    if len(_str) < 3:
        return _str
    else:
        #检查前四个字符，看看符不符合错误
        if (_str[0]  * 3) == _str[0:3]:
            #连续三个字符重复
            #根据测试用例，不允许出现三个连续的字符，要去掉只剩下两个
            return _str[0:2] + checkStr(_str[3:])
        elif  (_str[0] * 2 +  _str[2] * 2) == _str[0:4]:
            #从左至右处理，所以可以从前往后扫描
            #AABB
            return _str[0:3] + checkStr(_str[4:])
        else:
            #没有错误，向下
            return _str[0] + checkStr(_str[1:])
       '''
    

if __name__ == "__main__":
    lineNum = int(input())
    lineList  =  list()    #存储每一个字符串吧
    while lineNum:
        lineNum -= 1
        lineList.append(input())
    result = list()    #校对后的结果列表
    #逐个处理每个字符串
    for s in lineList:
        result.append(checkStr(checkStr(s)))
    for i  in result:
        print(i)
        
