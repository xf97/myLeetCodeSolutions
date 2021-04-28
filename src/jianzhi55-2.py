# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        #可以递归解决
        #可能空树
        #十三分钟，两次提交，时间击败-11.49%，空间击败-76.60%
        if root == None:
            return True
        else:
            #考察当前树
            if abs(self.getDepth(root.left) - self.getDepth(root.right)) > 1:
                return False
            #再考察两棵子树
            return self.isBalanced(root.left) and self.isBalanced(root.right) 

    def getDepth(self, _node):
        if _node == None:
            #空树
            return 0
        else:
            return max(self.getDepth(_node.left), self.getDepth(_node.right)) + 1
