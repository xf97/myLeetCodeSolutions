class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #干翻字节
        #最简单就是On2
        #但是可以哈希，用空间换时间
        #时间击败-96.48%，空间击败-19.08%
        digitAndIndex = dict()
        for index, i in enumerate(nums):
            if (target - i)  in digitAndIndex:
                #找到
                return [index,  digitAndIndex[target - i]]
            digitAndIndex[i] = index 
        #一定可以找到，所以以下返回无用
        return [0,  -1]
