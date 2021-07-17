class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        #18年做过的题了，现在再做一次
        #题目要求子序列最少有一个元素，题目也保证数组最少有一个元素
        result = nums[0]    #最大和
        tempResult = result #当前和
        #On一次遍历看能不能解决
        #当前和为正数
        #碰到正数，吃进来，然后更新最大值
        #碰到负数，先吃进来
        #和为负数
        #碰到正数，就直接把当前和更新为正数值，更新最大值
        #碰到负数，就更新为较大的那个负数值
        #两次提交，十分钟，时间击败-95.13%，空间击败-87.58%
        for i in nums[1:]:
            if tempResult >= 0:
                #当前和为正
                if i > 0:
                    tempResult += i
                    result =  max(result, tempResult)
                else:
                    tempResult += i
            else:
                #当前和为负
                if i > 0:
                    tempResult = i
                    result = max(result, tempResult)
                else:
                    tempResult = max(i ,tempResult)
                    result =  max(tempResult, result)
        return result
