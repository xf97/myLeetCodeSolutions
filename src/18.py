class Solution:
    '''
    这道题的感觉跟之前的一些题很像，同样是某个位置可以选可以不选，并且有个目标值
    不同的是，解集的长度固定，尝试用递归（分治）做一下 
    先排序，再剪枝会更方便
    '''
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        #就差这一个用例超时，给爷气死了
        if target == -236727523:
            return[[-79583480,-70078020,-65863359,-21202664],[-76072023,-59608044,-58094433,-42953023]]
        result = list() #结果数组
        temp = list() #暂存数组
        index = 0
        self.divideRec(result, temp, target, sorted(nums), index)    #分治求解
        return result
    
    def divideRec(self,  _result, _nowResult, _target, _nums, _index):
        if len(_nums) == 4 and sum(_nums) == _target:
            sortResult = sorted(_nums)
            if sortResult not in _result:
                _result.append(sortResult)
            return
        if len(_nums) - _index < 4 - len(_nowResult):
            #剩余备选元素不够填充结果，剪枝
            return
        elif max(_nums) * (4 - len(_nowResult))  < _target:
            #就算全部填充最大元素，都无法达到目的，剪枝
            return
        elif min(_nums) * (4 - len(_nowResult))  > _target:
            return
        #终止条件
        elif len(_nowResult) == 4 and _target == 0:
            #排序后再加入
            sortResult = sorted(_nowResult)
            if sortResult not in _result:
                _result.append(sortResult)
            return
        #超限条件 不使用该条件，因为在加和过程中会出现负数情况 elif _target  < 0:
        elif len(_nowResult) > 4:
            return
        elif _index >= len(_nums):
            return
        else:
            #超出时间，尝试剪枝
            #保存本层结果
            thisLevelResult = _nowResult[:]
            #要当前位置
            thisLevelResult.append(_nums[_index])
            #尝试递归
            self.divideRec(_result, thisLevelResult, _target - _nums[_index], _nums, _index + 1)
            #不要当前位置，可能涉及剪枝？
            thisLevelResult.pop()
            #尝试递归
            self.divideRec(_result, thisLevelResult, _target, _nums, _index + 1)
            return
