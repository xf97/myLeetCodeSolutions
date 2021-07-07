#终于找到一道acm模式了
#高兴
#老铁厂我来了
#前序遍历，看一下是不是升序，感觉这个方法不稳妥
#逐个遍历每个节点
#对于第i个节点，符合以下情况之一
#第2i+1个和第2i+2个节点分别小于大于本节点，题目没说可以等于
#或者，第2i+1个为空，和第2i+2个节点大于
#或者，第2i+1个小于，和第2i+2个节点为空
#开始

nodeValStr =  input()
#print(nodeValStr)
if nodeValStr == "None":
    #空树
    print(True)
else:
    nodeValsList  = [int(i) for  i in nodeValStr.split(",")]    #要求一次生成，不可用迭代器
    '''
    我人都傻了
    10,5,15,3,7,13,18这个是True
    10,5,15,3,11,13,18这个是False，我也是醉了
    我不服
    一看题解，结果还是中序遍历
    '''
    #print(nodeValsList)
    #开始遍历
    result = True    #可以应对空树情况
    length = len(nodeValsList)
    for i in range(0, length):
        leftNodeIndex = 2*i+1
        rightNodeIndex = 2*i+2
        if leftNodeIndex < length and rightNodeIndex < length:
            #要求符合条件1
            if nodeValsList[i] <= nodeValsList[leftNodeIndex] or nodeValsList[i] >= nodeValsList[rightNodeIndex]:
                result = False
                break
        elif leftNodeIndex < length and rightNodeIndex >= length:
            #右节点超限
            if nodeValsList[i] <= nodeValsList[leftNodeIndex]:
                result = False
                break
        else:
            #左右都超限了
            continue
    print(result)
