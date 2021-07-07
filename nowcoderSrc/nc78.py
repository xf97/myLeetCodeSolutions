# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#十五分钟，一次提交通过
class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        # write code here
        #在leetcode那边看了题解才做出来一道中等题，是罪过，因此惩罚自己多做一道简单题
        #怎么牛客上是核心代码模式呀，不高兴
        #翻转，用栈
        newHead = None    #新表头
        if not pHead or not pHead.next:
            #边界处理
            return pHead
        stack = list()
        #压入栈
        while pHead:
            stack.append(pHead)
            pHead = pHead.next
        #print(stack)
         #然后再出栈，出栈时反向链接
        newHead = stack.pop()    #记录表头
        #print(newHead.val)
        tempPtr = newHead    #反向链接指针
        while  len(stack):
            newNode = stack.pop()    #新节点
            #print(newNode.val)
            #反向链接
            tempPtr.next = newNode
            tempPtr = tempPtr.next
        tempPtr.next = None    #处理尾节点
        return newHead
                
                
