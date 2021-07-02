class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        #买最多的冰棒，那肯定是谁便宜买谁呀
        #这个中等题有点简单
        #十分钟，一次提交，时间击败 -46.94%，空间击败-14.78%
        costs.sort()
        result = 0
        index =  0
        #开始买
        while coins >= 0 and index < len(costs):
            coins -= costs[index]
            index += 1
            result += 1
        if  coins < 0:
            result  -= 1
        return result
