# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    '''
    感觉应该使用分治算法，加上双指针
    是一种穿针引线的感觉
    不分治，两个指针就搞定了，还比比来来那么多
    time defeat: 97.79%%
    space defeat: 76.57%
    '''
    def oddEvenList(self, head: ListNode) -> ListNode:
        #短路原则，不会报错
        if head == None or head.next == None or head.next.next == None:
            return head
        oddPointer = head   #奇数指针
        evenPointer = head.next #偶数指针
        #记录奇偶数链表的头和尾
        evenHead = head.next
        while evenPointer and evenPointer.next:
            #不拼接，直接改
            oddPointer.next = evenPointer.next
            oddPointer = oddPointer.next
            evenPointer.next = oddPointer.next
            evenPointer = evenPointer.next
        oddPointer.next = evenHead
        return head
