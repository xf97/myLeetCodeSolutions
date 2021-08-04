class Solution:
    def candy(self, ratings: List[int]) -> int:
        #干翻蚂蚁金服！
        #暂时饶蚂蚁金服一次，我想想困难题
        #感觉可以用动态规划做
        #从评分最低的孩子往两边动态规划
        #不行呀，[1,2,2,1]应该是6颗
        #get，看了题解，我觉得我可以
        #二十分钟，一次提交，时间击败-18.59%，空间击败-5.04%
        #边界情况处理
        length = len(ratings)
        if length == 1:
            return 1
        #从左到右
        left = [[0] for _ in range(length)]
        for i in range(length):
            if i > 0 and ratings[i] > ratings[i - 1]:
                #等于都不好使
                left[i] = left[i - 1] + 1
            else:
                left[i] = 1
        #从右到左
        right = [[0] for _ in range(length)]
        for i in range(length - 1, -1, -1):
            if i < length - 1 and ratings[i] > ratings[i + 1]:
                right[i] = right[i + 1] + 1
            else:
                right[i] = 1
        #要同时满足左右两个条件，所以选择最大的
        result = 0
        for i in range(length):
            result += max(left[i], right[i])
        return result
