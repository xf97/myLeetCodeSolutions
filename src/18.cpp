class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        #ok，爷来更新一年前做的题了
        #题目保证构成答案的四个数的下标，互不相同，欸，好条件
        #二十分钟，一次提交，时间击败-60.91%，空间击败-84.22%
        length = len(nums)
        result = list()
        nums.sort()
        #边界条件
        if length < 4:
            return result
        #第一第二层枚举，第三第四层并列
        for _1st in range(0, length - 3):
            #每一层，都要不重复的
            if _1st > 0 and nums[_1st - 1] == nums[_1st]:
                continue
            #第二层
            for _2nd in range(_1st + 1, length - 2):
                #然后依然要不重复的
                if _2nd != _1st + 1 and nums[_2nd - 1] == nums[_2nd]:
                    continue
                _4th = length - 1   #最后一个
                num = target - nums[_1st] - nums[_2nd]
                #开始第三层
                for _3rd in range(_2nd + 1, length - 1):
                    #跳过重复
                    if _3rd != _2nd + 1 and nums[_3rd - 1] == nums[_3rd]:
                        continue
                    #现在让_4th往里面缩
                    #缩就会减小
                    while _4th > _3rd and nums[_4th] + nums[_3rd] > num:
                        _4th -= 1
                    #判断一下结束
                    if _4th == _3rd:
                        #这一层没救了
                        break
                    if nums[_4th] + nums[_3rd] == num:
                        #找到一个
                        result.append([nums[_1st], nums[_2nd], nums[_3rd], nums[_4th]])
                    #找不到，下一圈
        return result
