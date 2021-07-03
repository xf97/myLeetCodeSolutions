class Solution:
    def frequencySort(self, s: str) -> str:
        #第一个想到的办法是哈希表
        if len(s) <= 2:
            #边界处理
            return s
        else:
            #时间复杂度是Onlogn，排序的复杂度
            #空间复杂度是On，字典的
            #居然没超时，这个中等题不太行
            #十分钟，一次提交，时间击败-54.49%，空间击败-65.15%
            result = str()
            charAndNumDict = dict()
            #先统计出现次数
            for i in s:
                if i not in charAndNumDict:
                    charAndNumDict[i] =  1
                else:
                    charAndNumDict[i] += 1
            #print(charAndNumDict)
            #然后按出现次数降序排列
            charAndNumList =sorted(charAndNumDict.items(),  key = lambda x:x[1], reverse = True)
            #现在开始遍历列表，拼接输出
            #print(charAndNumList)
            for item in charAndNumList:
                result += (item[0] * item[1])
            return  result
