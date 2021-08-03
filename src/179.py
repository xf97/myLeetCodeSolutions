class Solution:
    def cmp(self, num1, num2):
        '''
        swapFlag = 1
        #num1指向较短那个
        if len(num1) > len(num2):
            num1, num2 = num2, num1
            swapFlag = -1
        #遍历
        index = 0
        for n1, n2 in zip(num1, num2):
            index += 1
            #在这一轮就决出胜负
            if n1 < n2:
                return (-1) * swapFlag
            elif n1 > n2:
                return (1) * swapFlag
            else:
                continue
        #不分上下
        #看num2里包含零吗
        #包含0的出现的越后越好
        for n in num2[index:]:
            if n == "0":
                return (1) * swapFlag
            elif n < num1[-1]:
                #小于num1的最后一个，那么还是num1在前
                return 1 * swapFlag
        return (-1) * swapFlag
        '''
        #思路是对的，比较函数有点问题
        return int(num1 + num2) - int(num2 + num1)
    
    def largestNumber(self, nums: List[int]) -> str:
        #干翻蚂蚁金服！
        #想要重写排序的比较函数
        #四次提交，二十五分钟，学习了，时间击败-68.30%，空间击败-16.23%
        nums = [str(i) for i in nums]
        #我要降序排序
        sortedNums = sorted(nums, reverse = True, key = functools.cmp_to_key(self.cmp))
        #print(sortedNums)
        #边界处理
        if sortedNums[0] == "0":
            #最大数是0
            return "0"
        #拼接答案
        result = str()
        for i in sortedNums:
            result += i
        return result
