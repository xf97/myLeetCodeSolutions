# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        #昨天面试字节碰上了它的高级题，力扣25，我先来欺负下它的小弟
        #用递归做一下
        #十分钟，一次提交，时间击败-5.36%，空间击败-5.54%
        #昨天要是做这个题我就搞定了呀
        if head == None or head.next ==  None:
            return head
        #先把末尾给标记一下
        fakeHead  = ListNode(-1)
        temp = head
        while temp.next != None:
            temp = temp.next
        fakeHead.next  =  temp  #锁定结尾
        #开始翻转，递归
        self.re_reverseList(head, temp)
        #处理尾节点
        head.next = None
        return  fakeHead.next

    def re_reverseList(self, _head, _tail):
        if _head == _tail:
            #头尾重合，翻转终止
            return
        else:
            #否则，翻转
            prevNode = _head
            while prevNode.next != _tail:
                prevNode = prevNode.next
            #翻转
            _tail.next = prevNode
            #向下
            self.re_reverseList(_head, prevNode)
            return

