class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        #干翻字节，我来了
        #低买高卖，只能买卖一次吗？——是的，只能买卖一次，On2的算法
        #On2算法不通过，超时，198/211，说白了就是找小的在前面和高的在后面
        # 此方法会超时，题解中也是这个方法，照样通过不了
        #看了题解的第二种方法，有道理，On复杂度
        #时间击败-88.55%，空间击败-25.70%
        result = 0
        minPrice  = 10001   #最低价格，prices中元素都小于10000
        #卖一定在买之后
        #所以可以边找最小值边计算
        for price in prices:
            result = max(result,  price - minPrice)
            minPrice = min(minPrice, price)
        return result
        '''
        result = 0
        #边界情况
        if len(prices) == 0:
            return prices[0]
        buyDay = 0  #购买日
        length = len(prices)
        while buyDay <  length - 1:
            result  = max(result, max(prices[buyDay + 1:]) -  prices[buyDay])
            buyDay += 1
        return result
        '''
