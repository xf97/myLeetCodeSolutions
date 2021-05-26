# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        #最简单的方法，中序遍历，获取从小到大的序列
        #然后双指针向中间，时间复杂度On，空间复杂度On
        #题目保证输入的树最少有一个节点
        #八分钟，两次提交，时间击败-91.28%，空间击败-37.28%
        if root.left == None and root.right == None:
            return False
        #节点
        valList = list()
        #中序遍历
        def inorderDfs(_node, _list):
            if _node == None:
                return
            else:
                inorderDfs(_node.left, _list)
                _list.append(_node.val)
                inorderDfs(_node.right, _list)

        #中序深搜
        inorderDfs(root, valList)
        #然后左右双指针
        left, right = 0, len(valList) - 1
        while left < right:
            #要求两个节点
            if valList[left] + valList[right] == k:
                return True
            elif valList[left] + valList[right] > k:
                right -= 1
            else:
                left += 1
        return False
