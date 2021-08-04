class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        #开启今日的干翻蚂蚁金服
        #一个前指针，一个后指针
        #当前偶后奇时交换，然后两个指针推进
        #如果前偶后偶，后面推进
        #如果前奇后奇，前面退进
        #如果前奇后偶，都推进
        #边界处理
        #时间复杂度On，空间O1
        #十分钟，一次提交，时间击败-78.03%，空间击败-26.90%
        length = len(nums)
        if length <= 1:
            return nums
        left, right = 0, length - 1
        while left < right:
            leftResult = (nums[left] & 0x1) #奇1偶0
            rightResult = (nums[right] & 0x1)
            if leftResult == 0 and rightResult == 1:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
            elif leftResult == 0 and rightResult == 0:
                right -= 1
            elif leftResult == 1 and rightResult == 1:
                left += 1
            else:
                left += 1
                right -= 1
        return nums
