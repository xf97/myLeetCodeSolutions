# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
'''
基本思想-多指针
吐了，做成逆置单链表了，诶
修改，可以递归的做
time defeat: 76%
space defeat: 75%
time consuming: 1 hour
'''
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        #空链表或者只有一个节点 
        if not head or not head.next:
            return head
        #否则，原先的第二个节点就是新链表的头
        newHead = head.next
        #下一个节点就是缩小递归范围后的第三个节点开始的链表
        head.next = self.swapPairs(newHead.next)
        #将本来的头加到第二个节点
        newHead.next = head
        return newHead
        '''
            #大于等于三个节点的情况
            lastPreNode = None
            firstNode = head
            prePointer = head.next
            sufPointer = head.next.next
            while sufPointer != None or prePointer != None:
                print(firstNode.val, prePointer.val)
                #逆置相邻两个节点
                prePointer.next = firstNode
                firstNode.next = lastPreNode
                #更新指针
                lastPreNode = prePointer
                firstNode = sufPointer
                if not sufPointer:
                    break
                prePointer = sufPointer.next
                sufPointer = prePointer.next
            return prePointer
        '''
        
        
