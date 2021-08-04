class Solution:
    def cmp(self, num1, num2):
        #从头到尾比
        length1 = len(num1)
        length2 = len(num2)
        swapFlag = 1
        #num1是短的那个
        if length1 > length2:
            num1, num2 = num2, num1
            swapFlag = -1
        for n1, n2 in zip(num1, num2):
            #print(n1, n2, num1, num2)
            #从头到尾开始搞
            if n1 == n2:
                continue
            elif n1 > n2:
                return 1 * swapFlag
            else:
                return (-1) * swapFlag
        #如果n2更长
        #111, 11101
        #那就是n2强
        return (-1) * swapFlag

    def lexicalOrder(self, n: int) -> List[int]:
        #干翻蚂蚁金服
        #要重写cmp函数
        #自己的思路，很好，一次提交
        #二十五分钟，时间击败-34.64%，空间击败-5.28%
        #初始化
        nums = [str(i) for i in range(1, n + 1)]
        nums = sorted(nums, key = functools.cmp_to_key(self.cmp))
        return [int(i) for i in nums]
