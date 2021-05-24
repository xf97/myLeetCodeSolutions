# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: TreeNode) -> str:
        #题目保证输入不会为空树
        #题意都搞求不懂
        #时间复杂度-On, 空间复杂度-On
        #15分钟，一次提交，时间击败-84.51%，空间击败-57.75%
        #根据有没有孩子来区分
        if root == None:
            return ""
        elif root.left == None and root.right == None:
            #叶子结点
            return str(root.val)
        elif root.right == None:
            #只有左节点
            return str(root.val) + "(" + self.tree2str(root.left) + ")"
        else:
            #只有右节点或两个孩子节点都有
            return str(root.val) + "(" +  self.tree2str(root.left) + ")(" + self.tree2str(root.right) + ")"
