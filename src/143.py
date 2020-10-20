# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
'''
初步想法-双指针，由头尾向中间推进
进阶想法-使用list简化操作
time defeat: 90%
space defeat: 26%
'''
class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head == None or head.next == None:
            #极端情况
            return
        else:
            #是否可以简化操作-使用list
            nodeList = list()
            nowNode = head
            #填充list
            while nowNode:
                nodeList.append(nowNode)
                nowNode = nowNode.next
        
            preIndex, postIndex = 0, len(nodeList) - 1  #前后索引
            while preIndex < postIndex:
                #前索引需要使用保持在后索引之前
                #从头开始重构
                nodeList[preIndex].next = nodeList[postIndex]
                #更新前索引，方便后续连接
                preIndex += 1
                if preIndex == postIndex:
                    #相等时跳出
                    break
                #重构向后连接
                nodeList[postIndex].next = nodeList[preIndex]
                postIndex -= 1  #更新后索引
            #跳出时，前索引大于等于后索引
            nodeList[preIndex].next = None

                
        
