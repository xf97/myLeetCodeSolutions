class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        #寻找最高的山顶
        #题目保证数组长度大于3，并且一定是一个山脉数组
        #边界情况
        if len(arr) < 3:
            return -1
        else:
            #寻找递增末尾
            result = 0
            length = len(arr) - 1
            while result <= (length - 1):
                if arr[result] < arr[result + 1]:
                    result += 1
                else:
                    break
            return result
