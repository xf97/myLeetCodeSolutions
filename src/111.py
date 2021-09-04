# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        #很有意思这个题
        #干翻出这个题的公司
        #想用层序遍历
        #十分钟，一次提交，时间击败-75.29%，空间击败-66.16%
        if root == None:
            return 0
        dq = collections.deque()
        #根节点入队
        dq.append(root)
        result = 0  #深度
        flag = True
        while dq and flag:
            length = len(dq)    #这一层的长度
            #print(length)
            for i in range(length):
                node = dq.popleft() #出队
                if node.left == None and node.right == None:
                    #叶子结点
                    flag = False
                    break
                else:
                    #不是的话打入节点
                    if node.left:
                        dq.append(node.left)
                    if node.right:
                        dq.append(node.right)
            result += 1 #一层结束
        return result
