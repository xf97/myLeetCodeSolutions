# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    '''
    二十五分钟，很棒，一次提交，时间击败-16.29%，空间击败-74.19%
    '''
    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        result = list()
        #后序遍历
        def posterDfs(node):
            if node == None:
                return
            else:
                posterDfs(node.left)
                posterDfs(node.right)
                nonlocal result
                #print("xixi")
                result.append(str(node.val))
                return

        posterDfs(root)
        #print(",".join(result))
        return ",".join(result)
        

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        #重建后序遍历
        if len(data) == 0:
            return None
        poster = [int(i) for i in data.split(",")]
        #构造中序
        inorder = sorted(poster)
        #print(poster, inorder)
        #开始构造
        length = len(poster)
        root = self.buildTree(inorder, 0, length - 1, poster, 0, length - 1)
        return root

    def buildTree(self, inorder, sIn, eIn, poster, sPo, ePo):
        #空树情况
        if sIn > eIn or sPo > ePo:
            return None
        #拿到根
        rootVal = poster[ePo]
        #print(rootVal)
        #获得左子树长度
        leftLength = inorder.index(rootVal) - sIn
        #构造本节点
        root = TreeNode(rootVal)
        #构造左右节点
        root.left = self.buildTree(inorder, sIn, sIn + leftLength - 1, poster, sPo, sPo + leftLength - 1)
        root.right = self.buildTree(inorder, sIn + leftLength + 1, eIn, poster, sPo + leftLength, ePo - 1)
        return root

        

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
