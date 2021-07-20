class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #这种题是真的不会，看了题解，现在懂了
        #题目保证数组非空
        #这题就小饶字节一命，看看题解再做
        #时间复杂度On，空间复杂度O1
        #边界处理
        length = len(nums) 
        if length ==  1:
            return
        #要找到一个尽量靠右的数字，然后把在这个数字右边的较大数字交换过来（这个较大数要尽可能贴近较小数）
        #最后重新排列交换位置的后部序列
        #注意要相等，要掠过相等的那些数字，找到真正的较大数和较小数
        #三次提交，十五分钟，时间击败-97.38%，空间击败-32.10%
        smallNum = length -  2  #开始找较小数
        while smallNum >= 0 and  nums[smallNum] >= nums[smallNum + 1]:
            smallNum -= 1
        #停下时指向较小数
        if smallNum >= 0:
            #寻找较大数字，比较小数要大
            bigNum = length - 1
            while bigNum > smallNum and nums[bigNum] <= nums[smallNum]:
                bigNum -= 1
            #交换
            nums[smallNum], nums[bigNum] = nums[bigNum], nums[smallNum]
        #翻转后部排列
        #手动revsrse吧，不用多一个副本
        left, right = (smallNum + 1),  (length - 1)
        while left  <  right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
    
