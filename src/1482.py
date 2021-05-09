class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        #边界情况
        #看了题解，基本思想是跟我想的一致的
        #就是寻找小于某个值的连续子数组的数量
        #用二分确实是我没想到的
        #二十分钟，一次提交，时间击败-55.00%，空间击败-36.88%
        if (m * k) > len(bloomDay):
            return -1
        #用自己的代码写一遍
        #使用内嵌函数加快调用
        def canMake(_days):
            flowers = requests = 0  #flowers是成熟花朵的数量，requests是连续子数组的数量
            for i, flower in enumerate(bloomDay):
                if flower <= _days:
                    #一朵花成熟了
                    flowers += 1
                    #如果够一束花了
                    if flowers == k:
                        requests += 1
                        if requests == m:
                            return True
                        flowers = 0 #集满一束花，清空
                else:
                    flowers = 0 #没有连续大于，清空
            return requests == m

        #开始二分查找
        low, high = min(bloomDay), max(bloomDay)    #最小天数不会小于最小元素，不会大于最大元素
        while low < high:
            day = (low + high) // 2 
            #print(day)
            if canMake(day):
                #大了
                high = day
            else:
                #小了
                low = (day + 1)
        return low
