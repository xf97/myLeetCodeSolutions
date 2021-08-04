# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        #递归，每次比较两个节点
        #干翻蚂蚁金服
        #五分钟，一次提交，时间击败-80.00%，空间击败-50.35%
        #边界判断
        if root == None:
            return True
        def judgeSymmetric(node1, node2):
            if node1 == None and node2 == None:
                return True
            elif node1 == None:
                return False
            elif node2 == None:
                return False
            elif node1.val != node2.val:
                return False
            else:
                return judgeSymmetric(node1.left, node2.right) and judgeSymmetric(node1.right, node2.left)

        return judgeSymmetric(root.left, root.right)
