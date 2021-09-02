class Solution:
    def nextGreaterElement(self, n: int) -> int:
        #别看这个题难，其实我有一个土办法
        #干翻出这个题的公司
        #好像也可以排序哦
        #边界
        if n < 10:
            return -1
        #我感觉要单调栈
        #不可以，是剑指offer原题，困难题，我自己实现
        #三十分钟，python3里面对32位整数溢出还真是麻烦
        #四次提交，时间击败-87.78%，空间击败-56.25%
        nums = [i for i in str(n)]
        #print(nums)
        #为保证是最小的最大，交换位置要尽可能偏右
        #找到右边第一个a[i]>a[i-1]的位置
        length = len(nums)
        index = length - 1
        while index >= 1:
            if nums[index] > nums[index -1]:
                break
            else:
                index -= 1
        #index停下时指向i
        if index == 0:
            return -1
        left = index - 1
        while index < length:
            if nums[index] > nums[left]:
                index += 1
            else:
                break
        right = index - 1
        nums[left], nums[right] = nums[right], nums[left]
        #然后翻转left之后的
        left = left + 1
        right = length - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
        #print(nums) 
        result = int("".join(nums))
        #print(result)
        #然后再判断越界和不变
        if result == n:
            return -1
        #print(2**32, "**")
        if abs(result) > 2147483647:
            return -1
        return result
