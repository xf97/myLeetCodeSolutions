# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        #烦了，有个Leetcode的题整的心烦
        #干翻字节
        #用python写个二叉树
        #递归，写完去吃饭了
        #五分钟，一次提交，时间击败-87.08%，空间击败-66.25%
        #边界处理
        if root == None:
            return True
        #开始递归
        return self.isSymmetric2Nodes(root.left, root.right)

    def isSymmetric2Nodes(self, _leftNode, _rightNode):
        if _leftNode == None and _rightNode == None:
            return True
        elif _leftNode == None or _rightNode == None:
            return False
        elif _leftNode.val != _rightNode.val:
            return False
        else:
            #两个节点值相等，继续向下
            return self.isSymmetric2Nodes(_leftNode.left, _rightNode.right) and self.isSymmetric2Nodes(_leftNode.right, _rightNode.left)
