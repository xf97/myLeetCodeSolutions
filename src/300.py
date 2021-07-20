class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        #先想出了一个On2的做法，感觉On2过不去
        #试试
        #今日份最后一次干翻字节
        #严格递增，不能相等
        #就差一步，自己的想法，用动态规划就可以了，第i个元素对应的各自 dp[i] =  dp[j] + 1,  0<=j<k并且nums[j]<nums[i]
        #十五分钟，一次提交，时间击败-59.4%，空间击败-34.73%
	#On2过得去
        for index in range(length):
            result.append(1)    #每个位置至少有长度1的子串
            #开始正序过来
            for innerIndex in range(index):
                if nums[index] > nums[innerIndex]:
                    result[index]  = max(result[index], result[innerIndex] + 1)
        return  max(result)
