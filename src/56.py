class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        #干翻字节！今日份最后一题
        #感觉要排序，按开始位置排序
        #Onlogn时间复杂度，额外要构造结果，On的空间复杂度
        #边界处理
        #十分钟，有点轻敌，多用了两次提交
        #还是不错的，想到的做法也实现出来了
        #时间击败-88.17%，空间击败-74.38%
        #最少有一个区间
        length = len(intervals)
        if length == 1:
            return intervals
        else:
            result = list() #结果
            intervals.sort(key = lambda x : x[0])   #按开始位置升序排序
            index = 0   #遍历下标
            while index < length:
                #取第一个区间
                #可以原地修改
                aInter = intervals[index]
                #向后走
                tempIndex = index + 1
                while tempIndex < length and aInter[1] >= intervals[tempIndex][0]:
                    #我的结束大于等于他的开始，那么更新我的结束
                    aInter[1] = max(intervals[tempIndex][1], aInter[1])
                    tempIndex += 1
                result.append(aInter)
                index= tempIndex    #新的一组
            return result
