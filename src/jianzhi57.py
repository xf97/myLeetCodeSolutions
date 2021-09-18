class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        #我上来直接就是一个On
        #十分钟，一次提交，时间击败-46.45%，空间击败-53.28%
        result = list()
        #滑动窗口
        left, right = 1, 2
        while left < right:
            total = (left + right) * (right - left + 1) // 2
            if total == target:
                result.append([i for i in range(left, right + 1)])
                left += 1
            elif total > target:
                left += 1
            else:
                right += 1
        return result
