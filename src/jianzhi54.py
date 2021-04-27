# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        #简单方法-利用二叉搜索树的中序遍历是递增数列
        #题目保证不是空树
        #题目保证k小于树节点个数，因此k不会下标溢出
        #还是做个边界处理吧
        #十分钟，一次提交通过，时间击败-70.18%，空间击败-45.87%
        if root == None:
            return -1
        else:
            valList = list()    #节点值列表
            self.inorderTraversal(root, valList)
            #返回第k大的元素
            return valList[len(valList) - k]

    def inorderTraversal(self, _node, _valList):
        if _node == None:
            #空节点处理
            return
        else:
            #左根右遍历
            self.inorderTraversal(_node.left, _valList)
            #中间节点值压入
            _valList.append(_node.val)
            #右子树
            self.inorderTraversal(_node.right, _valList)
            return 
