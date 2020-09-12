# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

'''
version 1: 时间击败-33.49%， 空间击败-13.60%
version 2: 时间击败-70.95%， 空间击败-12.97%
'''

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        result = list() #int-list, store avarage value
        nodeList = list() #本层节点列表
        nodeList.append(root) #根节点入队
        self.bfs(nodeList, result)  #广度优先遍历
        return result

    def bfs(self, _nodeList, _result):
        #终止情况
        if len(_nodeList) == 0:
            return
        else:
            #计算本层均值
            newNodeList = list()
            total = float(0)
            for  node in _nodeList:
                total += node.val
                '''
                同时填入下一层节点
                '''
                if node.left != None:
                    newNodeList.append(node.left)
                if node.right != None:
                    newNodeList.append(node.right)
            total /= len(_nodeList)
            _result.append(total)   #记录本层均值
            #递归进入下一层
            self.bfs(newNodeList, _result)
            return
