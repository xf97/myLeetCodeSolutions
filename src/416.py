class Solution:
    '''
    每个元素都有两种情况，要，还是不要
    轻松超时 我太难了 我感觉我的递归也可以做(如果时间无限的话)
    这居然也是个动态规划问题？戳中死穴
    我的方法-通过36个
    使用官方题解-自己打注释
    '''
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        #小于两个元素，无法分割
        if n < 2:
            return False
        
        total = sum(nums)
        #和为奇数，无法分割
        if total % 2 != 0:
            return False
        #目标就是找到数组中的一部分，其和为数组的一半
        target = total // 2
        dp = [True] + [False] * target
        #enumerate用于同时列出索引和元素值
        #这个状态转移的思想将绝杀，可惜绝不得
        for i, num in enumerate(nums):
            for j in range(target, num - 1, -1):
                dp[j] |= dp[j - num]
        
        return dp[target]
    '''
    def canPartition(self, nums: List[int]) -> bool:
        #数组之和为奇数，不能分割
        if sum(nums) % 2 != 0:
            return False
        else:
            index = 0   #当前考虑的索引
            temp = list()   #暂存弹出元素数组
            cache = nums[:] #缓存
            return self.recFind(nums, temp, index,  cache)
        
    def recFind(self, _list, _anotherList, _index, _cache):
        if sum(_list) == sum(_anotherList):
            #找到可分割的解
            return True
        elif sum(_list) < sum(_anotherList):
            return False
        elif _index == len(_cache):
            #遍历完数组，都无法找到解，返回false
            return False
        else:
            #尝试当前元素
            tempList = _list[:]
            tempCache = _anotherList[:]
            tempCache.append(_cache[_index])
            tempList.remove(_cache[_index])
            result1 = self.recFind(tempList, tempCache, _index + 1, _cache)
            #不尝试当前元素
            result2 = self.recFind(_list, _anotherList, _index + 1, _cache)
            return result1 or result2
            '''
