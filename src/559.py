"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        #深度优先搜索，取深度
        #时间复杂度On，空间复杂度，取决于递归次数
        #可以递归
        #十分钟，被一开始的层序表示迷惑了，一次提交，时间击败-93.65%，空间击败-90.52%
        #边界处理
        if root == None:
            #空节点处理
            return 0
        elif len(root.children) == 0:
            #叶节点处理，因为算的是节点总数
            return 1
        else:
            depth = 0
            for i in root.children:
                depth = max(depth, self.maxDepth(i))
            return depth + 1

    
