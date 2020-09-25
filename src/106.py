# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    '''
    大师，我悟了，中序用来判断左右，后序从后向前获得节点
    '''
    '''
    仍然递归
    1. 根据后序序列的最后一个元素建立根结点；
    2. 在中序序列中找到该元素，确定根结点的左右子树的中序序列；
    3. 在后序序列中确定左右子树的后序序列；
    4. 由左子树的后序序列和中序序列建立左子树；
    5. 由右子树的后序序列和中序序列建立右子树
    '''
    '''
    time debeat: 14%
    space debeat: 11%
    '''
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if len(postorder) == 0:
            return None
        elif len(postorder) ==1:
            return TreeNode(postorder.pop())
        elif len(postorder) ==2:
            #当只有2个时，构造一棵树回去
            #根节点
            root = TreeNode(postorder.pop())
            #while len(postorder) > 0:
            #构造下级节点
            newNode = TreeNode(postorder.pop())
            #根据左右构造路径 
            if inorder.index(newNode.val) < inorder.index(root.val):
                root.left = newNode
            else:
                root.right = newNode
            return root
        else:
            #根节点 
            root = TreeNode(postorder[-1])
            #右子中序和后序
            rightInOrder = inorder[inorder.index(root.val) + 1 :]
            rightPostOrder = postorder[-1 - len(rightInOrder) : -1]
            root.right = self.buildTree(rightInOrder, rightPostOrder)
            #左子中序和后序
            leftInOrder = inorder[:inorder.index(root .val)]
            leftPostOrder = postorder[: -1 - len(rightInOrder)]
            root.left = self.buildTree(leftInOrder, leftPostOrder)
            return root
        
