class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        #先产生数组，然后再按位异或
        #时间复杂度-On，空间复杂度-On
        #因为start大于0，所以数组元素都为非负整数
        #三分钟，一次提交，时间击败-64.78%，空间击败-64.50%
        #感觉能够边生成元素边异或，这样就能节约时间和空间
        nums = list()
        for i in range(n):
            nums.append(start + (2 * i))
        #已获得数组，然后按位异或
        result = 0
        for i in nums:
            result = (result ^ i)
        return result
