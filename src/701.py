# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
基本思路-根据搜索二叉树的性质，搜索到合适的位置
构造新节点，然后组合二叉树，二叉树可用递归
time defeat: 32.36%
space defeat: 47.90%
time consuming: less than 15 mins
'''
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        #递归终止情况，要么空树要么叶子
        if not root:
            return TreeNode(val)
        #根据搜索树性质，开始搜索合适位置
        if val > root.val:
            #在右边
            root.right = self.insertIntoBST(root.right, val)
        else:
            #在左边
            root.left = self.insertIntoBST(root.left, val)
        return root
    
        
        
