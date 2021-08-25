class Solution:
    def mergeSoft(self, nums, temp, left, right):
        #归并边界
        if left >= right:
            return 0
        #先归并下去
        mid = (left + right) // 2
        reverseCount = self.mergeSoft(nums, temp, left, mid) + self.mergeSoft(nums, temp, mid + 1, right)
        #然后开始处理本层的
        l = left    #左边数组指针
        r = mid + 1 #右边数组指针
        pos = l   #写入位置指针
        #开始比较
        while l < mid + 1 and r <= right:
            if nums[l] <= nums[r]:
                temp[pos] = nums[l]
                pos += 1
                reverseCount += (r - (mid + 1))
                l += 1
            else:
                temp[pos] = nums[r]
                r += 1
                pos += 1
        #处理多出来的那部分
        #先左后右
        for i in range(l, mid + 1):
            #前面的比较大，逆序了
            temp[pos] = nums[i]
            pos += 1
            reverseCount += (r - (mid + 1))
        for i in range(r, right + 1):
            temp[pos] = nums[i]
            pos += 1
        #把归并值赋值回去
        nums[left: right + 1] = temp[left: right + 1]
        return reverseCount


    def reversePairs(self, nums: List[int]) -> int:
        #干翻出这种难题的公司
        #逆序对，一种暴力方法是On2，看测试用例和困难的难度就知道过不去
        #我直接看题解
        #绝了归并排序的思路
        #只有当左边数组指针右移时，判断右边数组指针前有几个数字
        length = len(nums)
        temp = [0] * length #归并暂存数组
        return self.mergeSoft(nums, temp, 0, length - 1)
