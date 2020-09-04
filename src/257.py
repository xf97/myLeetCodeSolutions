# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        #递归实现
        #深度优先遍历
        if root == None:
            return list()
        pathList = list()
        path = str()
        self.recFind(root, path, pathList)
        return pathList
    
    def recFind(self, _node, _nowPath, _pathList):
        temp = _nowPath[:]
        if len(temp) != 0:
            temp += "->"
        if _node.left == None and _node.right == None:
            temp += str(_node.val)
            _pathList.append(temp)
        else:
            if _node.left != None:
                self.recFind(_node.left, temp + str(_node.val), _pathList)
            if _node.right != None:
                self.recFind(_node.right, temp + str(_node.val), _pathList)
        return
