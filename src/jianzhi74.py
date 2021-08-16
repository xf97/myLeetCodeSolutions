class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        #干翻蚂蚁金服！
        #按开始位置排序，然后合并
        #二十五分钟，不太细心，提交了三次
        #时间击败-78.13%，空间击败-59.38%
        length = len(intervals)
        #边界处理
        if length <= 1:
            return intervals
        intervals.sort(key = lambda x : x[0])   #按开始位置排序
        #print(intervals)
        result = list() #结果
        index = 0
        while index < length:
            end = intervals[index][1]   #结束位置
            nex = index + 1 #下一个探索位置
            while nex < length and end >= intervals[nex][0]:
                #我的结束大于等于你的开始，可以更新，注意要更新大于那个结束
                end = max(end, intervals[nex][1])
                nex += 1
            #不大于了，记录
            result.append([intervals[index][0], end])
            index = nex
        #可能需要注意末尾处理
        return result
