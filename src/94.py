# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
	'''
	时间击败：96.63%
	空间击败：6.76%
	'''
        '''
        先序-根左右
        中序-左根右
        后序-左右根
        先用递归
        '''
        result = list() #结果数组
        path = list()   #遍历路径数组
        path.append(root)
        self.inorderTravel(path, result)    #递归寻找
        return result
    
    def inorderTravel(self, _path, _result):
        #终止情况
        if len(_path) == 0:
            return
        #弹出当前节点
        nowNode = _path.pop(0)
        #极端情况
        if nowNode == None:
            return
        #print(nowNode.val)
        #入队情况
        if nowNode.left != None:
            _path.append(nowNode.left)
            #继续向左子树遍历
            self.inorderTravel(_path, _result)
        #记录结果
        _result.append(nowNode.val)
        #print("hahahah")
        #右子树
        if nowNode.right != None:
            #print(nowNode.right.val)
            _path.append(nowNode.right)
            self.inorderTravel(_path, _result)
        return
