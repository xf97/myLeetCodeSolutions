# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        #求二叉树深度，深度优先，可以前序
        #空树的深度定义为0
        #可能为空树
        #十分钟，一次提交，时间击败-76.76%，空间击败-34.49%
        if root == None:
            return 0
        else:
            depth = [0]   #深度，使用列表，可以随参数传递，是可变对象
            tempDepth = 0   #暂时深度
            self.dfs(root, tempDepth, depth)  #开始深度搜索
            return depth[0]

    def dfs(self, _node, _nowDepth, _depth):
        if _node == None:
            #空节点处理
            return
        elif _node.left == None and _node.right == None:
            #叶节点
            _nowDepth += 1
            #print(_nowDepth, _depth)
            _depth[0] = max(_nowDepth, _depth[0])
            #print(_depth)
            return
        else:
            #非叶节点
            _nowDepth += 1
            self.dfs(_node.left, _nowDepth, _depth)
            self.dfs(_node.right, _nowDepth, _depth)
            return
