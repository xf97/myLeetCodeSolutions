# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
'''
不用双指针，而是用数字记录长度
'''
#time defeat-82.76%
#space defeat-8.92%
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        #极端情况
        #边际情况，0-1-2个节点
        #空链表
        if not head:
            return head
        #1个节点
        elif not head.next:
            return None
        #两个节点
        elif not head.next.next:
            #根据n返回节点
            if n == 1:
                head.next = None
                return head
            else:
                return head.next
        else:
            #大于三个节点的时候
            #先获取链表长度
            listLen = 0
            nowNode = head  #指向头部的另一个指针
            while nowNode != None:
                listLen += 1
                nowNode = nowNode.next
            #应对只有三个的情况
            if listLen == n:
                return head.next
            #然后第二遍扫描链表
            nowNode = head
            nowLen = listLen - n - 1
            while nowLen > 0:
                nowNode = nowNode.next
                nowLen -= 1
            #停下来时候，nowNode指向被删除节点的前一个
            nowNode.next = nowNode.next.next
            return head
                
        
