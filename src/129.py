# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        #干翻字节！
        #下星期开始干翻阿里
        #和113一样，递归+回溯
        #不用边界处理
        #很熟练，十二分钟，一次提交，时间击败-96.93%，空间击败-20.83%
        result = [0]  #结果，题目保证正整数，使用列表进行参数传值
        aPath = 0   #一条路径，用整数的化这样就不用回退
        def getPathSum(_node, _path, _result):
            if _node == None:
                return
            elif _node.left == None and _node.right == None:
                #叶节点
                _path = (_path * 10) + _node.val
                #加到结果了
                _result[0] += _path
                return
            else:
                #非叶节点
                _path = (_path * 10) + _node.val
                getPathSum(_node.left, _path, _result)
                getPathSum(_node.right, _path, _result)
                return

        getPathSum(root, aPath, result)
        return result[0]
