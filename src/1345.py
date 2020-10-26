class Solution:
    '''
    最基本的思路－双重遍历
    time defeat: 26.46%
    space defeat: 5.09%
    '''
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        result = list() #存储结果的数组
        for index, value in enumerate(nums):
            #同时取出下标和值，避免与自己比较－其实可以和自己比较，因为相等不计入
            num = 0 #计数
            for aIndex, aValue in enumerate(nums):
                if aIndex == index:
                    continue
                elif aValue <  value:
                    num += 1
                else:
                    continue
            result.append(num)
        return result
