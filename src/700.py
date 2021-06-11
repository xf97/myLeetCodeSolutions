# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        #根据二叉搜索树的性质，一次遍历应该就可以了,Ologn
        #五分钟，一次提交，时间击败-46.87%，空间击败-96.92%
        #有目标性的去检索，贼不走空，不走没用的节点
        #递归
        if root == None:
            return None
        elif root.val == val:
            return root
        elif root.val > val:
            #根的值比目标值大，目标值在左子树
            return self.searchBST(root.left, val)
        else:
            #根的值比目标值小，目标值在右子树
            return self.searchBST(root.right, val)
