class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        #今日份干翻蚂蚁金服！
        #感觉要用字典
        #顺便记录个最大数
        #不用字典，遍历，On2可以
        #十五分钟，一次提交，时间击败-5.02%，空间击败-37.37%
        #看了题解，用单调栈会更好
        #碰到这种更大更小的题，就也要考虑单调栈
        #numsAndIndex = dict()
        length = len(nums)
        #空数组怎么办，题目保证不会空数组
        if length <= 1:
            return [-1]
        else:
            biggerNum = [-1] * (length)
            for i in range(length):
                #每个元素，要记录此刻的开始下标
                startIndex = i
                j = i + 1
                while j != startIndex:
                    #找一圈都没有，那自然是没有了
                    #print(i, j)
                    if j == length:
                        #循环搜索回来
                        j = 0
                    elif nums[j] > nums[i]:
                        biggerNum[i] = nums[j]
                        break
                    else:
                        j += 1
            return biggerNum
