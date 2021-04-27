# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        #初始想法-快慢指针法，先遍历一次，看那个链表长一些
        #然后再遍历一遍，长的链表的出发节点会比短的往前挪
        #On时间复杂度，O1空间复杂度
        #然后遍历前移，不能用值相等来判断同一节点，因为有值重复
        #一次提交，十分钟打代码，时间击败-17.99%，空间击败-75.23%
        lenA, lenB = 0, 0 #两个链表的长度
        pointA, pointB = headA, headB   #遍历指针
        while pointA != None or pointB != None:
            #只要有一个链表还没到结束，就向前遍历
            if pointA != None:
                lenA += 1
                pointA = pointA.next    #记录，前移
            if pointB != None:
                lenB += 1
                pointB = pointB.next
        #重置双指针
        pointA, pointB = headA, headB
        #挪动长链表指针
        if lenA > lenB:
            while lenA != lenB:
                pointA = pointA.next
                lenA -= 1
        if lenB > lenA:
            while lenB != lenA:
                pointB = pointB.next
                lenB -= 1
        #现在统一了，开始同步遍历
        #如果两边遍历到None了，就表示没有相交的地方
        while pointA != None and pointB != None:
            if pointA is pointB:
                #重合
                return pointA
            else:
                pointA = pointA.next
                pointB = pointB.next
        #没有相交
        return None
