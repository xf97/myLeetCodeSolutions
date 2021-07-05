class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #又来玷污中等题
        #原地删除，有序数组
        #绝了，以前双指针只会两头对进的，现在又多了一种快慢双指针
        #现在我自己来做
        #五分钟，一次提交，时间击败-92.90%，空间击败-59.15%
        length =   len(nums)
        if length <= 2:
            #因为要保留两个连续的，所以数组长度小于等于2时不处理
            return length
        slow, fast = 2, 2   #慢指针指处理好的数组长度，快指针指扫描到的原数组长度
        while fast < length:
            if nums[fast] != nums[slow - 2]:
                #不多于两个重复
                #赋值
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        return  slow
