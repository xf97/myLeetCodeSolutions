# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node):
        if not node:
            #空节点
            return 0, 0
        #后序遍历，从底向上累加
        #偷左的和不偷左的
        leftPick, leftIgnore = self.dfs(node.left)
        rightPick, rightIgnore = self.dfs(node.right)
        #返回结果
        #不偷本节点，则子节点可偷可不偷
        return node.val + leftIgnore + rightIgnore, max(leftPick, leftIgnore) + max(rightPick, rightIgnore)

    def rob(self, root: TreeNode) -> int:
        #我先层序遍历，算出每层的和
        #然后当作一个简单的打家劫舍做了
        #大败亏输，都没分析清楚题目
        #重来
        #四次提交，二十五分钟，时间击败-92.46%，空间击败-73.80%
        return max(self.dfs(root))
        '''
        if not root:
            return 0
        vals = list()
        nodeQueue = list()
        nodeQueue.append(root)
        while nodeQueue:
            #本层有几个节点
            size = len(nodeQueue)
            totalSum = 0
            #逐个遍历他们
            for i in range(size):
                node = nodeQueue.pop(0)
                totalSum += node.val
                if node.left:
                    nodeQueue.append(node.left)
                if node.right:
                    nodeQueue.append(node.right)
            vals.append(totalSum)
        #print(vals)
        #开始dp，不是连接在一起的
        #如果小于3层
        if len(vals) < 3:
            return max(vals)
        dp = [0] * len(vals)
        dp[0] = vals[0]
        dp[1] = max(vals[0], vals[1])
        for i in range(2, len(vals)):
            dp[i] = max(dp[i - 1], dp[i - 2] + vals[i])
        print(dp)
        return dp[-1]
        '''
        
