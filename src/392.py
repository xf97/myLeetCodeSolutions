class Solution:
    '''
    刷两道简单题泄愤
    基本思路-寻找每个字符的位置，如果都存在，那么要求数组有序，否则false
    time defeat: 82%
    space defeat: 88%
    time consuming: less than 6 mins
    '''
    def isSubsequence(self, s: str, t: str) -> bool:
        position = [-1] #记录子序列中每个字符位置的数组，使用-1初始化，使用-1初始化的目的是考虑到首次搜索下标
        for i in s:
            newPosition = t.find(i, position[-1] + 1) #从上次搜索结果的末尾开始
            if newPosition == -1 or newPosition >= len(t):
                #存在字符不存在于t中
                return False
            else:
                position.append(newPosition)    
        #判断元素是否有序
        if position == sorted(position):
            return True
        else:
            return False
