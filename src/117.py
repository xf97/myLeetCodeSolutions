"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
'''
想到的思路-广度优先，递归，保存每一层，在本层内指定next节点
time defeat: 92.97%
space defeat: 47.15%
time consuming: less than 21 minutes
'''
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        #极端情况
        if  not root:
            return
        thisLevel = [root]  #初始化递归首层
        self.bfsSearch(thisLevel)   #开始递归
        return root #返回根节点
    
    def bfsSearch(self, _thisLevel):
        #递归返回情况
        if len(_thisLevel) == 0:
            return
        #先构建下一层的节点
        nextLevel = list()
        for node in _thisLevel:
            if node.left != None:
                nextLevel.append(node.left)
            if node.right != None:
                nextLevel.append(node.right)
            #print(node.val)
        #print("一层")
        #再设置本层节点的next值
        for index in range(0, len(_thisLevel)):
            #如果是最后一个节点，设置为空
            if index == len(_thisLevel) - 1:
                _thisLevel[index].next = None
            else:
                #否则，关联两个节点
                _thisLevel[index].next = _thisLevel[index + 1]
        self.bfsSearch(nextLevel)
        return
        
        
