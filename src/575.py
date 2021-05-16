class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        #因为是偶数数组，//2和/2没有区别
        #一分钟，一次提交，时间击败-87.33%，空间击败-25.98%
        #说实话，题目有一些难以理解
        #因为有偶数个糖果，所以一定能平分
        #所以就是求集合中有多少种数字，要注意特殊情况
        #即集合中有多于(n//2)种糖果，但是因为要平分
        #所以最多也就能分得n//2种糖果
        return min(len(set(candyType)), len(candyType) // 2)
