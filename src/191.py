class Solution:
    def hammingWeight(self, n: int) -> int:
        #规律，(n-1)&n会把该数最右侧的1变成0
        #无符号整数，不需要应对边界情况
        #五分钟完成，时间击败：41.71%，空间击败：38.19%
        result = 0
        while n != 0:
            result += 1
            n = (n - 1) & n
        return result
