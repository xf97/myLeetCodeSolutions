class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        #时间复杂度为On的算法，一次循环
        #数组每个元素都是正数
        #数组大小1-100
        #十分钟，一次提交，时间击败-37.12%，空间击败-76.93%
        if len(nums) == 1:
            return nums[0]
        maxResult = 0
        lPoint = 0
        tempMax = 0
        while lPoint < len(nums):
            rPoint = lPoint + 1
            #构建(严格)升序子数组
            while rPoint < len(nums) and nums[rPoint] > nums[rPoint - 1]:
                rPoint += 1
            #停下时已经越过升序部分
            #计算子数组和
            tempMax = sum(nums[lPoint: rPoint])
            maxResult = max(maxResult, tempMax)
            #更新左指针
            lPoint = rPoint
        return maxResult
