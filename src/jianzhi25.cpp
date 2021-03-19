/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //感觉上一次是看了答案写的，这次我自己写
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //归并排序，这个问题可以用递归的方法解决，因为缩小后的问题与原问题是一类问题
        //空链表处理
        //一次通过，时间击败：76.89%，空间击败：48.60%
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        //然后就谁小要谁
        ListNode * mergedNode = nullptr;
        //注意升序
        if(l1->val <= l2->val){
            mergedNode = l1;
            //推进一个节点
            mergedNode->next = mergeTwoLists(l1->next, l2);
        }
        else{
            mergedNode = l2;
            mergedNode->next = mergeTwoLists(l1, l2->next);
        }
        return mergedNode;
    }
};
