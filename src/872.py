# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        #先序遍历，保持节点从左到右的顺序
        #记录叶节点，时间复杂度On，空间复杂度是两个树的叶节点数量之和（不足On）
        #题目保证两棵树至少有一个节点
        #四分钟，一次提交，时间击败-54.23%, 空间击败-64.92%
        #边界还是处理一下
        if root1 == None and root2 == None:
            return True
        else:
            #先序遍历深搜函数
            def preOrderDfs(_node, _leavesList):
                if _node == None:
                    return
                elif _node.left == None and _node.right == None:
                    #叶节点
                    _leavesList.append(_node.val)   #int为不可变变量，每次赋值都是完整拷贝
                    #根左右
                    preOrderDfs(_node.left, _leavesList)
                    preOrderDfs(_node.right, _leavesList)
                else:
                    #普通节点
                    preOrderDfs(_node.left, _leavesList)
                    preOrderDfs(_node.right, _leavesList)

            tree1Leaves = list()    #树1叶子结点值（从左到右）
            tree2Leaves = list()
            #开始先序遍历
            preOrderDfs(root1, tree1Leaves)
            preOrderDfs(root2, tree2Leaves)
            return tree1Leaves == tree2Leaves
