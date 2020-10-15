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
我做过更难版本的，广度优先遍历，递归，保存上一层结果
'''
#time defeat: 85.75%
#space defeat: 5.31%
#time consuming: 25 mins

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            #空树情况
            return root
        else:
            nodeList = list()
            nodeList.append(root)   #本层入队
            self.bfsConstruct(nodeList) #开始广度递归
            return root
    
    def bfsConstruct(self, _nodeList):
        #print("hahaha")
        #递归返回情况
        if not _nodeList:
            return 
        else:
            #print("hahaha")
            #print([node.val for node in _nodeList])
            #构筑下层节点
            nextLevelNodeList = list()
            for node in _nodeList:
                #完美二叉树，每个节点都有两个儿子
                if node.left :
                    nextLevelNodeList.append(node.left)
                if node.right:
                    nextLevelNodeList.append(node.right)
            #然后，再连接本层节点
            for index, node in enumerate(_nodeList):
                #print(node.val)
                if index == len(_nodeList) - 1:
                    node.next = None
                else:
                    node.next = _nodeList[index + 1]
            #进入下层递归
            self.bfsConstruct(nextLevelNodeList)
            return
        
