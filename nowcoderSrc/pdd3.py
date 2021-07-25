'''
牛客上面的题真的给我恶心到了
'''

#这个题，排序，应该就可以了，因为是一对一关系
#时间复杂度Onlogn
#真的难使，牛客这个

def getResult():
    kidNums = int(input())
    kidList = [int(i) for i in input().split()]
    choNums = int(input())
    choList = [int(i) for i in input().split()]
    #print(kidNums, kidList, choNums, choList)
    #排序
    choList.sort(reverse=True)    #降序
    kidList.sort(reverse=True)
    result = 0
    kidIndex = 0
    choIndex = 0
    while kidIndex < kidNums and choIndex < choNums:
        if choList[choIndex] >= kidList[kidIndex]:
            result += 1
            choIndex += 1
            kidIndex += 1
        else:
            #不能满足，问后面的孩子
            kidIndex += 1
    print(result)

getResult()
