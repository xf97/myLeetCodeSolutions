class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        #如果暴力的话，时间复杂度就是On2
        #十分钟，第一次提交，超时，34/46
        #边界处理
        n = len(nums)
        ans = 0
        for i in range(30):
            c = sum(((val >> i) & 1) for val in nums)
            ans += c * (n - c)
        return ans
        '''
        #最后还是要做一只抄题解的菜狗
        if len(nums) <= 1:
            return 0
        else:
            result = 0
            def getHammingDistance(_num1, _num2):
                bNum1 = bin(_num1)[2:]  #不要开头的0b
                bNum2 = bin(_num2)[2:]
                #bin方法的返回值是字符串
                if len(bNum1) < len(bNum2):
                    bNum1, bNum2 = bNum2, bNum1
                #将bNum2的长度补足
                while len(bNum2) != len(bNum1):
                    bNum2 = ("0" + bNum2)
                #然后计算汉明距离
                distance = 0
                for num1Bit, num2Bit in zip(bNum1, bNum2):
                    if num1Bit != num2Bit:
                        distance += 1
                    else:
                        continue
                #print(bNum1, bNum2, distance)
                return distance

            for index, num1 in enumerate(nums):
                for num2 in nums[(index + 1) : ]:
                    result += (getHammingDistance(num1, num2))
            return result
            '''
