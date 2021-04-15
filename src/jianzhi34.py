# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        #深度优先搜索
        #节点值可能为负数
        #中等题，很棒，二十分钟，一次提交
        #时间击败：76.90%，空间击败：84.01%
        result = list() #返回结果
        if not root:
            return result
        else:
            nowPath = list()
            self.pathSumDfs(root, nowPath, target, result)
            return result

    def pathSumDfs(self, _node, _nowPath, _target, _result):
        #叶节点是终止情况
        #往上回退时要减掉当前节点值
        if _node == None:
            #空节点
            return 
        elif _node.left == None and _node.right == None:
            #叶节点
            #print(_node.val, _target)
            if _node.val == _target:
                #找到目标
                _nowPath.append(_node.val)
                _result.append(_nowPath[:])
                #释放该节点
                _nowPath.pop()
                #返回
                return
            else:
                #该路径不符合要求
                return
        else:
            #正常节点，根左右
            _nowPath.append(_node.val)
            #左节点
            self.pathSumDfs(_node.left, _nowPath, _target - _node.val, _result)
            #右节点
            self.pathSumDfs(_node.right, _nowPath, _target - _node.val, _result)
            #释放该节点
            _nowPath.pop()
            return
