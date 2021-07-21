class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        #逐步分解，递归向下
        #数组中无重复元素
        #数组大小为1-6
        #十分钟，一次提交，递归缩小问题规模
        #没有耍赖，时间击败-78.15%，空间击败-28.84%
        '''
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
        '''
        #回溯法
        #把每一位都交换
        #理解了，干翻字节，要恢复正常
        #一次提交，十分钟，时间击败-94.65%，空间击败-21.04%
        def  trackback(_frist = 0):
            if _frist == length:
                #已经回溯到最后一个
                result.append(nums[:])
            else:
                #试探每个位置
                #first指的是第一位
                for i in range(_frist, length):
                    #交换
                    nums[_frist], nums[i] = nums[i], nums[_frist]
                    #往下试探，继续交换其他的
                    trackback(_frist + 1)
                    #回溯法
                    nums[i], nums[_frist] = nums[_frist], nums[i]
        
        length =  len(nums)
        result  = list()
        trackback()
        return result
