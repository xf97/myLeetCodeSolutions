/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//time defeat: 88%
//space defeat: 99%
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //归并排序
        ListNode * firstNode = new ListNode(0);   //firstNode是伪头节点
        ListNode * curNode = firstNode;
        //开始归并
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                curNode->next = l1;
                l1 = l1->next;
            }
            else{
                curNode->next = l2;
                l2 = l2->next;
            }
            curNode = curNode->next;
        }
        //当跳出循环是，必定一个为空
        if(l1 == nullptr){
            curNode->next = l2;
        }
        else{
            curNode->next = l1;
        }
        return firstNode->next;
    }
};
