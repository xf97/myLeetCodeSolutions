# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
　　'''
    空间击败：25%
    时间击败: 64%
    '''	
    def invertTree(self, root: TreeNode) -> TreeNode:
        #新想法，二叉树问题，直接在本函数上递归
        #从叶子节点向上翻转，就不用考虑记录上层关系
        #并且下层翻转后上层再翻转，就能实现“对称式的翻转”
        #极端情况
        if not root:
            return
        else:
            #向下到达叶子节点，并接收翻转值
            left = self.invertTree(root.left)
            right = self.invertTree(root.right)
            #翻转左右儿子
            root.left, root.right = right, left
            return root
        '''
         #广度优先遍历，逐层向下，翻转赋值
        if not root:
            #root为空，返回
            return
        #使用递归
        self.bfs([root])
        return root
        
    def bfs(self, _list):
        if len(_list) == 0:
            return
        else:
            valueList = list()
            nodeList = list()
            #遍历本层每一个元素
            for node in _list:
                #对空节点进行特殊处理
                if node:
                    #记录赋值
                    valueList.append(node.val)
                    #下层节点入队
                    if node.left != None:
                        nodeList.append(node.left)
                    if node.right != None:
                        nodeList.append(node.right)
                else:
                    #空值压入，但不压入下层
                    valueList.append(None)
            #翻转赋值
            valueList.reverse()
            #翻转本层
            for i in range(0, len(_list)):
                _list[i].val = valueList[i]
            #进入下一层
            self.bfs(nodeList)

        '''
