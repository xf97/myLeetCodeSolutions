# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

'''
基本思路，边遍历边保存
如果碰见之间保存过的节点，就有环
time defeat: 5.12%
space defeat: 84.38%
time consuming: less than 20 mins
'''
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        appearNode = list()
        #极端情况
        if not head or head.next == None:
            return False
        else:
            #首节点入队
            appearNode.append(head)
            nowNode = head.next
            #逐节点遍历，直至最后一个
            while nowNode != None:
                if nowNode in appearNode:
                    #出现环
                    return True
                else:
                    appearNode.append(nowNode)
                    nowNode = nowNode.next
            return False
        
