/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //链表题用c++做舒服
        //干翻字节！
        //ok，可以， 归并排序
        //时间复杂度On，空间复杂度O1
        //十分钟，一次提交，时间击败-97.07%，空间击败-62.80%
        //边界情况处理 
        if(l1 ==  nullptr || l2 ==  nullptr){
            l1 = (l1 ==  nullptr) ? l2 : l1;
            return l1;
        }
        ListNode * newHead  = new  ListNode();  //用个假头结点
        ListNode * pointer =  newHead;
        while(l1 && l2){
            //开始归并
            if(l1->val < l2->val){
                pointer->next = l1;
                pointer = pointer->next;
                l1 = l1->next;
            }
            else{
                pointer->next = l2;
                pointer = pointer->next;
                l2 = l2->next;
            }
        }
        //处理不等长节点
        l1 = (l1 == nullptr) ? l2 : l1;
        while(l1){
            pointer->next = l1;
            pointer = pointer->next;
            l1 = l1->next;
        }
        //处理尾节点
        pointer->next = nullptr;
        return newHead->next;
    }
};
