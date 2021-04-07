class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        #先用简单的，调库法
        #时间代价就是排序的o(logn)
        #五分钟，一次提交，时间击败：70.90%，空间击败：85.54%
        if len(arr) <= k:
            return arr
        sortedList = sorted(arr)
        return sortedList[:k]
        #还有一种方法是利用快排的切分函数，当被切分的元素刚好是第k个时，意味着左边前k个已经是最小的了
        #最后还有一种是堆排序，那个我用C++做吧
