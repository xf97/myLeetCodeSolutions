class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        #诶，一看就感觉是动态规划
        #诶，一看提交成功率，就知道不是我能做出来的简单动态规划
        length = len(nums)
        if length == 1:
            return 1
        #是子序列不是子串
        #所以不在乎空格
        dp = [1] * length   #当i为止的最长子串
        count = [1] * length #最长子串数量
        maxLength = 0   #最长子串长度
        for i in range(1, length):
            #分段处理，从前向后计算
            for j in range(i):
                if nums[i] > nums[j]:
                    #出现递增情况
                    if dp[j] + 1 > dp[i]:
                        #最长子串长度+1
                        dp[i] = dp[j] + 1
                        count[i] = count[j] #但是最长子串数量不增加
                    elif dp[j] + 1 == dp[i]:
                         #最长子串数量增加
                         count[i] += count[j]
            maxLength = max(maxLength, dp[i])
        #最后统计结果
        result = 0
        #print(maxLength, count, dp)
        for i in range(length):
            if dp[i] == maxLength:
                result += count[i]
        return result
