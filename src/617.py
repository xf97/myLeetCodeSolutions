# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

'''
总体思想　递归遍历，构造新树返回　
一些细节　相同顺序遍历两棵树，每经过一个节点，就进行一次判断
'''

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
	#时间击败 63.05%
	#空间击败 5.15%
        #如果一边为空，就可以直接返回另一棵树（无论是否为空）
        if not t1:
            return t2 
        if  not t2:
            return t1 
        
        #若两边都不为空，则产生新节点　
        newNode = TreeNode(t1.val + t2.val)
        #同向合并
        newNode.left = self.mergeTrees(t1.left, t2.left)
        newNode.right = self.mergeTrees(t1.right, t2.right)
        return newNode
        '''
        if t1 == None and t2 ==None:
            return None
        else:
            TreeNode newTreeRoot
            self.dfsTwoTrees(t1, t2, newTreeRoot)
            return newTreeRoot


        def dfsTwoTrees(self, _tree1Node, _tree2Node, _newTreeNode):
            if _tree1Node == None and _tree2Node == None:
                _newTreeNode == None
                return
            elif  _tree1Node != None or _tree2Node  != None:
                if _tree1Node != None:
                    _newTreeNode.val = _tree1Node.val
                    _newTreeNode.left = _tree1Node.left
                    _newTreeNode.right = _tree1Node.right
                    self.dfs(_tree1Node.left, None, _newTreeNode.left)
                    self.dfs(_tree1Node.right, None, _newTreeNode.right)
                elif _tree2Node != None:
                    _newTreeNode.val = _tree2Node.val
                    _newTreeNode.left = _tree2Node.left
                    _newTreeNode.right = _tree2Node.right
                    self.dfs(None, _tree2Node.left, _newTreeNode.left)
                    self.dfs(None, _tree2Node.right,  _newTreeNode.right)
                return
            else:
                _newTreeNode.val = _tree1Node.val + _tree2Node.val
                self.dfs(_tree1Node.left, _tree2Node.left, _newTreeNode.left)
                self.dfs(_tree1Node.right, _tree2Node.right,  _newTreeNode.right)
                return
                '''
