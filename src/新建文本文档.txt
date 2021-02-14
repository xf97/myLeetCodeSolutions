# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
头大
time defeat: 98.9%
space defeat: 11.14%
'''
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        #遍历，拼接
        #递归
        #边界情况
        if s.left == None and s.right == None and t.left == None and t.right == None:
            return s.val == t.val
        sRes = []
        tRes = []
        def dfs(root, _result):
            if not root:
                return _result.append("a")  #a是空节点标志
            _result.append(str(root.val))
            dfs(root.left, _result)
            dfs(root.right, _result)
        #拼接字符串
        dfs(s, sRes)
        dfs(t, tRes)
        sStr = "".join(sRes)
        tStr = "".join(tRes)
        print(sStr, tStr)
        return tStr in sStr