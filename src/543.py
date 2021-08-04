# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDepth(self, node):
        if node == None:
            return 0
        else:
            #注意，不一定经过根节点
            leftDepth = self.getDepth(node.left)
            rightDepth = self.getDepth(node.right)
            self.result = max(self.result, leftDepth + rightDepth + 1)
            return max(leftDepth, rightDepth) + 1

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        #干翻蚂蚁金服
        #递归解决
        #直径 = 左子树深度加右子树深度
        #时间复杂度On，空间是递归需要的递归栈On
        #对新概念不太了解，犯了几次错
        #递归边界处理
        self.result = 1
        if root == None:
            return 0
        else:
            self.getDepth(root)
            return self.result - 1
