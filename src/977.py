class Solution:
    '''
    今天赶时间，先用python吧
    这道题有点奇怪-就用了1分钟
    time defeat-99.72%
    space defeat-5.22%
    time consuming-1 min
    '''
    def sortedSquares(self, A: List[int]) -> List[int]:
        newList = [item * item for item in A]
        return sorted(newList)
