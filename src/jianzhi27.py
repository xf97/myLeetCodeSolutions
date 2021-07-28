# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        #干翻蚂蚁链
        #递归，交换左右节点
        #两分钟，一次提交，时间击败-96.00%，空间击败-33.28%
        #递归边界
        if root == None:
            return None
        else:
            root.left, root.right = root.right, root.left
            self.mirrorTree(root.left)
            self.mirrorTree(root.right)
            return root
