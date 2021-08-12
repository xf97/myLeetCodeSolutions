class Solution:
    def findMin(self, nums: List[int]) -> int:
        #干翻腾讯CSIG
        #最简单的办法，我先耍赖
        #一分钟，一次提交，时间击败-79.09%，空间击败-32.81%
        #return min(nums)
        #不耍赖了，正常做
        #常用方法是On
        #要用二分
        #要确定最小值在哪一边
        #元素互不相同
        #思路对的，但是这个题太迷惑了，确实看了题解
        #五次提交，三十分钟，时间击败-98.22%，空间击败-27.99%
        #边界处理
        #长度小于3的
        left, right = 0, len(nums) - 1
        while left < right:
            #可以相等
            middle = (left + right) // 2
            if nums[middle] > nums[right]:
                left = middle + 1
            else:
                right = middle
        return nums[left]
