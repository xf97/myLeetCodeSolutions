class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        #逐步分解，递归向下
        #数组中无重复元素
        #数组大小为1-6
        #十分钟，一次提交，递归缩小问题规模
        #没有耍赖，时间击败-78.15%，空间击败-28.84%
        result = list()
        if len(nums) == 1:
            result.append(nums[:])
            return result
        for i in nums:
            remainList = nums[:]
            remainList.remove(i)
            remainResult = self.permute(remainList)
            for j in remainResult:
                j.insert(0, i)
                result.append(j[:])
        return result
