class Solution:
    '''
    基本思想－靠count
    time defeat: 42.08%
    space defeat: 5.42%
    time consuming: 10 mins
    '''
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        if len(arr) == 1:
            return True
        else:
            appearCount = list()    #出现次数数组
            #遍历每个元素
            for item in set(arr):
                temp = arr.count(item)
                if temp in appearCount:
                    return False
                else:
                    appearCount.append(arr.count(item))
            return True
