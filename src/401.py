class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        #三次提交，十五分钟 ，时间击败-22.27%，空间击败-18.28%
        #边界情况
        if turnedOn >  8:
            return []
        result = list() #结果数组
        #开始枚举
        for hour in range(12):
            for  minute in range(60):
                #bin方法返回字符串  
                if  bin(hour).count("1") + bin(minute).count("1") == turnedOn:
                    #需要字符串格式化
                    result.append(f"{hour}:{minute:02d}")
        return result
        '''
        #方法不对，看了题解，反向枚举才是正确的，出乎意料
        #已经了解，拆分给定的时间，然后逐个返回
        #边界情况 
        if  turnedOn ==  0 or turnedOn >= 8:
            return []
        hourLimit = (turnedOn >   4) ?  4 : turnedOn    #最大时间数量 
        result =  list()
        for hour in range(0, hourLimit +  1):
            result.expand(self.getTime(hour, turnedOn -  hour))
        return  result

        def  getTime(self,  _time)
         '''

