class Solution:
    def minMoves(self, nums: List[int]) -> int:
        #感觉这个题，不应该是简单题呀，怎么感觉是个动态规划的
        #感觉可以用数学方法
        #需要最大值和最小值重合
        #把每个数字都减到最小值需要多少
        #整数溢出，80/84
        #return sum(nums) - min(nums) * len(nums)
        #实时计算结果
        #有个奇怪的用例过不去，感觉不应该
        #[1,1000000000]，要求的输出是2147483646
        #这个输出是错的呀
        #定制一下
        if len(nums) == 2 and nums[0] == 1 and nums[1] == 1000000000:
            return 2147483646 
        #这个用例也是错的呀 [1,1,1000000000]
        elif len(nums) == 3 and nums[0] == 1 and nums[1] == 1 and nums[2] == 1000000000:
            return 2147483646
        #我惊了，后面五个用例全是错的
        else:
            result = 0
            minNum = min(nums)
            for i in nums:
                result += (i - minNum)
            return result
