# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        #特殊情况：空链表，只有一个节点的链表，删除的是头节点，删除的是尾节点
        #用python写个链表的题
        '''
        耗时15分钟
        时间击败：74.55%
        空间击败：82.21%
        '''
        if head == None or head.next == None:
            return None
        elif head.val == val:
            #删除头节点
            return head.next
        else:
            #应对一般情况和删除尾节点的情况
            #这题跟原题不太一样，原题传入了要删除的节点，该题传入的节点的值
            #必须遍历
            pNode = head
            while pNode.next.val != val:
                pNode = pNode.next
            #pNode的下一个节点即为要删除的节点
            #该语句可应对被删除节点是尾节点的情况
            pNode.next = pNode.next.next
            return head
