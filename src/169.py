class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        #好像是有个投票法，可以On时间复杂度O1空间复杂度完成
        #又被字节拒了，难受，先干翻阿里巴巴吧
        #题目保证数组非空并且总是存在多数元素
        #一次提交，时间击败-94.65%，空间击败-31.31%
        length = len(nums)
        if length == 1:
            return nums[0]
        #开始投票
        target = nums[0]
        vote = 1
        for i in range(1, length):
            if nums[i] == target:
                vote += 1
            else:
                vote -= 1
                if vote:
                    continue
                else:
                    target = nums[i]
                    vote = 1
        return target
