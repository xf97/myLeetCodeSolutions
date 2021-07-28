class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        #感觉用python3好做一些
        #干翻阿里巴巴
        #十五分钟，一次提交
        #感觉并没有想象那么难，时间击败-95.99%，空间击败-52.21%
        ver1List = [int(i) for i in version1.split(".")]
        ver2List = [int(i) for i in version2.split(".")]
        #shortIndex = 0
        for v1, v2 in zip(ver1List, ver2List):
            if v1 == v2:
                continue
            elif v1 > v2:
                return 1
            else:
                return -1
            #shortIndex += 1 
        #停下时，要检查长字符串的剩余部分
        swapFlag = 1
        if len(ver1List) < len(ver2List):
            ver1List, ver2List = ver2List, ver1List #保证ver1是较长那一个
            swapFlag = -1
        #查看剩余的每一部分是不是都等于0
        for i in range(len(ver2List), len(ver1List)):
            if ver1List[i]:
                return 1 * swapFlag
            else:
                continue
        return 0
