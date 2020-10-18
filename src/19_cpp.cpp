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
/*
不用双指针，而是用数字
time defeat: 100%
space defeat: 5.05%
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //边际情况
        if(head == NULL){
            return NULL;
        }
        else if(head->next == NULL){
            return NULL;
        }
        else if(head->next->next == NULL){
            if(n == 1){
                head->next = NULL;
                return head;
            }
            else{
                return head->next;
            }
        }
        else{
            int listLen = 0;
            ListNode * nowNode = head;
            while(nowNode != NULL){
                nowNode = nowNode->next;
                listLen ++;
            }
            if(listLen == n){
                return head->next;
            }
            nowNode = head;
            int nowLen = listLen - n - 1;
            while(nowLen > 0){
                nowNode  = nowNode->next;
                nowLen --;
            }
            nowNode->next = nowNode->next->next;
            return head;
        }
    }
};
