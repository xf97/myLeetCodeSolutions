class Solution:
    def minArray(self, numbers: List[int]) -> int:
        #今日最后一次剑指 (指累了)
        #二分查找的做
        '''
        二分，当中间元素大于前面的数字时，说明最小元素在后面，向后收窄
        当中间元素小于前面数字时，向前收窄
        考虑特殊情况，当三个数字一样时只能顺序查找
        [4 5 6 7 1 2 3]
        time defeat: 86%
        space defeat: 43%
        '''
        sIndex = 0
        eIndex = len(numbers) - 1
        while numbers[sIndex] >= numbers[eIndex]:
            if eIndex - sIndex == 1:
                return numbers[eIndex]
            mid = (sIndex + eIndex) // 2
            #特殊情况
            if numbers[mid] == numbers[sIndex] and numbers[mid] == numbers[eIndex]:
                return self.seqSearch(numbers, sIndex, eIndex)
            elif numbers[mid] >= numbers[sIndex]:
                sIndex = mid
            elif numbers[mid] <= numbers[eIndex]:
                eIndex = mid
        return numbers[sIndex]

    def seqSearch(self, _nums, _sIndex, _eIndex) -> int:
        result = _nums[_sIndex]
        for i in range(_sIndex, _eIndex + 1):
            if _nums[i] < result:
                result = _nums[i]
        return result
