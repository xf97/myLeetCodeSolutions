class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        #一遍扫描，时间复杂度On
        #12分钟，一次提交，时间击败-94.30%，空间击败-81.24%
        if len(nums) <= 1:
            return 1
        length = 1  #连续递增长度
        index = 0   #遍历下标
        tempLength = 1  #用于遍历的标
        while index < (len(nums) - 1):
            if nums[index + 1] > nums[index]:
                #严格递增
                #print("hahah", nums[index])
                index += 1
                tempLength += 1
            else:
                length = max(tempLength, length)
                tempLength = 1
                index += 1
        length = max(tempLength, length)
        return length
