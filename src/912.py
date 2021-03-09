class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        #我理解了快排的思路了
        #现在我要动手重拳出击了
        #44%, 52%
        endIndex = len(nums)
        if endIndex <= 1:
            return nums
        else:
            #调用快排
            self.quickSort(nums, 0, endIndex - 1)
            return nums

    def quickSort(self, _nums, _startIndex, _endIndex):
        print(_nums)
        if _startIndex == _endIndex:
            #终止递归条件
            return
        else:
            #切分，返回切分位置并排序切分位置左右
            partitionIndex = self.partitionAndSort(_nums, _startIndex, _endIndex)
            #找到一个元素的位置后，向左右递归
            if partitionIndex > _startIndex:
                self.quickSort(_nums, _startIndex, partitionIndex - 1)
            elif partitionIndex < _endIndex:
                self.quickSort(_nums, partitionIndex + 1, _endIndex)

    def partitionAndSort(self, _nums, _startIndex, _endIndex):
        if len(_nums) == 0 or _startIndex < 0 or _endIndex >= len(_nums):
            #异常值
            return -1
        else:
            #首先，拿到切分点
            index = random.randint(_startIndex, _endIndex)
            #然后，把切分点的值放到最后去
            _nums[_endIndex], _nums[index] = _nums[index], _nums[_endIndex]
            #开始交换
            small = _startIndex - 1
            index = _startIndex
            #不要等于，等于是最后切分元素存放的位置了
            while index < _endIndex:
                #每个元素跟切分的元素相比较
                if _nums[index] < _nums[_endIndex]:
                    #小于，就进行操作
                    small += 1
                    if small != index:
                        #交换small和index
                        _nums[small], _nums[index] = _nums[index], _nums[small]
                index += 1
            small += 1
            #把切分元素放到自己的位置
            _nums[small], _nums[_endIndex] = _nums[_endIndex], _nums[small]
            return small
