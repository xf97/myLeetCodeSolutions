# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        '''
        之字形打印，用两个栈，交叉层数，先从左向右然后从右向左
        中等题，两次提交完成，25分钟，时间击败：52.46%，空间击败：39.41%
        '''
        result = list() #结果
        if root == None:
            return result
        else:
            #两个栈，用列表方便一些
            #只在队尾操作
            _1stNodeStack = list()
            _2ndNodeStack = list()
            flag = 0    #0就是从左往右压入，1就是从右往左压入
            #压入根节点
            _1stNodeStack.append(root)
            aLevelNode = list() #单层结果
            #开始遍历
            while len(_1stNodeStack) != 0:
                #弹出栈顶
                temp = _1stNodeStack.pop()
                #压入
                aLevelNode.append(temp.val)
                #然后压进去子节点
                if flag & 0x1 == 0:
                    #先左子后右子
                    if temp.left != None:
                        _2ndNodeStack.append(temp.left)
                    if temp.right != None:
                        _2ndNodeStack.append(temp.right)
                else:
                    #先右子后左子
                    if temp.right != None:
                        _2ndNodeStack.append(temp.right)
                    if temp.left != None:
                        _2ndNodeStack.append(temp.left)
                #然后判断是否一层结束
                if len(_1stNodeStack) == 0:
                    #那么记录本层结果
                    #print(aLevelNode)
                    result.append(aLevelNode)
                    aLevelNode = list()
                    #然后赋值给_1st
                    #利用python的特性，交换引用就可以了
                    _1stNodeStack, _2ndNodeStack = _2ndNodeStack, _1stNodeStack
                    flag += 1
            return result
                
                
