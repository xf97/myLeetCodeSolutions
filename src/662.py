# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        #用序号
        #每个节点的左节点是2i，右节点是2i+1
        #边界处理
        if root == None:
            return 0
        #还是要层序遍历，然后给每个节点编号
        nodes = list()
        aLevel = [(root, 1)]
        while aLevel:
            nodes.append(aLevel[:])
            nextLevel = list()
            for n in aLevel:
                if n[0].left:
                    nextLevel.append((n[0].left, 2 * n[1]))
                if n[0].right:
                    nextLevel.append((n[0].right, 2 * n[1] + 1))
            aLevel = nextLevel[:]
        #print(len(nodes))
        result = 0
        #逐层计算最大宽度
        for level in nodes:
            index = [node[1] for node in level]
            result = max(result, max(index) - min(index) + 1)
        return result   

        '''
        nodes = [(root, 1)]
        index = 0
        #遍历，编号
        while index < len(nodes):
            (node, i) = nodes[index]
            index += 1
            if node:
                if node.left:
                    nodes.append((node.left, 2 * i))
                if node.right:
                    nodes.append((node.right, 2 * i + 1))
        print([node[1] for node in nodes])
        nums = [node[1] for node in nodes]
        #然后计算每层宽度
        result = 0
        index -= 1
        while index > 0:
            lastLevelIndex = nums[index] // 2
            tempResult = index
            #print(tempResult, lastLevelIndex)
            while tempResult > 0 and nums[tempResult] > lastLevelIndex:
                tempResult -= 1
            result = max(result, nums[index] - nums[tempResult + 1] + 1)
            index = tempResult
        return result
        '''
