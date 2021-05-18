"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        #上班累，就划下水
        #递归整完，一次变量，时间复杂度-On，空间复杂度-On
        #三分钟，一次提交，时间击败-68.03%，空间击败-28.05%
        #边界处理
        result = list()
        if root == None:
            return result
        else:
            #后序深度
            def posterDfs(_node, _list):
                if _node == None:
                    return
                else:
                    for child in _node.children:
                        posterDfs(child, _list)
                    _list.append(_node.val)
                    return

            posterDfs(root, result)
            return result
