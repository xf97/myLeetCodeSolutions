# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        #先来简单方法，我遍历还不行吗
        #五分钟，一次提交， 时间击败-62.71%，空间击败-63.80%
        #题目保证非空
        if root.left == None and root.right == None:
            return -1
        nodeValList = list()
        def preOrderDfs(_node, _list):
            if _node == None:
                return
            else:
                _list.append(_node.val)
                preOrderDfs(_node.left, _list)
                preOrderDfs(_node.right, _list)

        preOrderDfs(root, nodeValList)
        nodeValList = sorted(list(set(nodeValList)))
        if len(nodeValList) >= 2:
            return nodeValList[1]
        else:
            return -1
