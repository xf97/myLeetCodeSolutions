class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        #最简单的方法，产生中毒时间序列，然后去重返回长度
        #两分钟，超出时间限制，20/38
        #改用一次遍历
        #五分钟，三次提交，时间击败-91.37%，空间击败-81.53%
        #边界处理
        if len(timeSeries) == 0 or duration == 0:
            return 0
        else:
            '''
            poisonTime = list()
            for i in timeSeries:
                for time in range(i, i + duration):
                    poisonTime.append(time)
            return len(set(poisonTime))
            '''
            result = 0  #总中毒时间
            lastPoisonTime = -1 #上一次中毒的结束时间
            for time in timeSeries:
                if lastPoisonTime < time:
                    #加上所有的中毒时间，然后更新
                    result += duration
                    lastPoisonTime = (time + duration - 1)
                else:
                    #减去重合时间
                    result += (duration - (lastPoisonTime - time + 1))
                    lastPoisonTime = (time + duration - 1)
            return result
