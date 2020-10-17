# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
#time defeat: 76%
#space defeat: 5%
#总体想法-分治，逐步向下
class Solution:
    def addTwoNodes(self, _resultNode, _node1, _node2, _carry):
	#终止情况
        if _node1 == None and _node2 == None and _carry == 0:
            return None
	#当两链表不对齐时，补齐链表
        if not _node1:
            _node1 = ListNode(0, None)
        if not _node2:
            _node2 = ListNode(0, None)
	#构造新节点
        val = _node1.val + _node2.val + _carry
        newCarry = 0
        if val >= 10:
            newCarry = val // 10
            _resultNode.val = val - newCarry * 10
        else:
            _resultNode.val = val
        #print(_node1.val, _node2.val, _resultNode.val)
        newNode = ListNode(0, None)
        _resultNode.next = self.addTwoNodes(newNode, _node1.next, _node2.next, newCarry)
        return _resultNode
        
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
	#极端情况
        if l1.val == 0 and l1.next == None:
            return l2
        elif l2.val == 0 and l2.next == None:
            return l1
        else:
	    #普遍情况
            newNode = ListNode(0, None)
            return self.addTwoNodes(newNode, l1, l2, 0)
        

                
                
        
