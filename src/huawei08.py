#用dict

import sys

#50%, 83%
def mergeRecord():
    #读取输入
    inputLines = sys.stdin.readlines()[1:]
    keyAndValueList = [i[:-1] for i in inputLines]
    keyAndValueDict = dict()
    for i in keyAndValueList:
        #读取键和值
        [key, value] = i.split()
        if int(key) in keyAndValueDict:
            #已经存在
            keyAndValueDict[int(key)] += int(value)
        else:
            keyAndValueDict[int(key)] = int(value)
    for key in sorted(keyAndValueDict.keys()):
        print(key, keyAndValueDict[key])
    
if __name__ == "__main__":
    mergeRecord()
