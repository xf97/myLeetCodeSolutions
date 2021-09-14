class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        #先搜一遍，确定每个元素出现的第一个和最后一个位置
        #二十分钟，一次提交，时间击败-68.49%，空间-19.29%
        charAndIndex = dict()
        for index, i in enumerate(s):
            if i in charAndIndex:
                charAndIndex[i][1] = index
            else:
                charAndIndex[i] = [index, index]
        #print(charAndIndex)
        #然后，合并区间
        interval = sorted(list(charAndIndex.values()))
        #print(interval)
        result = list() #合并后的区间
        length = len(interval)
        index = 0
        while index < length:
            start, end = interval[index][0], interval[index][1]
            nex = index + 1
            #print(index)
            while nex < length:
                #print(nex, "***")
                if interval[nex][0] >= start and interval[nex][1] <= end:
                    #包含
                    nex += 1
                elif interval[nex][0] >= start and interval[nex][0] < end and interval[nex][1] > end:
                    #交叉
                    end = interval[nex][1]
                    nex += 1
                else:
                    #不包含
                    result.append([start, end])
                    break
            if nex == length:
                #处理末尾情况
                result.append([start, end])
            index = nex
        #print(result)
        return [(i[1] - i[0] + 1) for i in result]
    '''
    不是很能理解题目的内核是什么，不管什么，同一个字母的出现区间信息应该还是需要的
    但我还是做出来了
    time defeat: 99.21%
    space defeat: 5.01%
    '''
    '''
    def partitionLabels(self, S: str) -> List[int]:
        appearIndex = dict()
        #遍历字符串，获取每个字母的出现和结束位置
        for index, char in enumerate(S):
            if char not in appearIndex:
                appearIndex[char] = list()
                appearIndex[char].append(index)
                appearIndex[char].append(-1)    #填入默认结束值
            else:
                    appearIndex[char][1] = index
        #根据出现位置，组织返回的答案
        #appearIndex的字母都是按下标从前到后排列，所以不会回溯
        result = list(sorted(appearIndex.values(), key = lambda x: x[0]))
        temp = list()
        index = 0
        sPos, ePos = result[index][0], result[index][1]
        while index < len(result):
            if sPos < result[index][0] and  ePos > result[index][1] and result[index][1] != -1:
                #被包含，继续搜索
                index += 1
            elif ePos > result[index][0] and ePos < result[index][1]:
                #边界扩展
                ePos = result[index][1]
                index += 1
            elif ePos < result[index][0]:
                #转移到下一组
                #记录之前结果
                if [sPos, ePos] not in temp:
                    temp.append([sPos, ePos])
                sPos, ePos = result[index][0], result[index][1]
                index += 1
            else:
                index += 1
        temp.append([sPos, ePos])
        #计算每段长度
        result = list()
        for item in temp:
            #出现单个字母一组的情况
            if item[1] == -1:
                result.append(1)
            else:
                result.append(item[1] - item[0] + 1)
        return result
        '''
