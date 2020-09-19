# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

'''
时间击败: 62%
空间击败: 18%
'''

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        #递归遍历
        result = list()  #左叶子数组
        #极端情况
        if not root:
            return 0
        else:
            #进入递归
            self.inorderRec(result, root, -1)
            return sum(result)
    
    #flag用于标记是左叶子还是右叶子
    def inorderRec(self, _result, _node, _flag):
        #中止情况
        if _node  == None:  #空节点，返回
            return
        if _flag == 1 and _node.left == None and _node.right == None:   #找到左叶子，记录值
            _result.append(_node.val)
            #print(_result)
            return
        else:   #否则递归遍历
            self.inorderRec(_result, _node.left,  1)
            self.inorderRec(_result, _node.right, 0)
            return
        
            
        
