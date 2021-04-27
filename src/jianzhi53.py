class Solution:
    def search(self, nums: List[int], target: int) -> int:
        #这题稍显疑惑，我要耍赖了
        #nums长度可能为0
        #数组已经排序
        #一分钟，一次提交，时间击败-6.64%，空间击败-89.95%
        #三分钟，循环方法，时间复杂度On，时间击败-97.49%，空间击败-13.00%
        if len(nums) == 0:
            return 0
        elif nums[0] > target or nums[-1] < target:
            return 0
        else:
            #return nums.count(target)
            #不耍赖做一次
            count = 0
            for i in nums:
                if i == target:
                    count += 1
                else:
                    continue
            return count
