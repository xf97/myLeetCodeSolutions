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
    ListNode* oddEvenList(ListNode* head) {
        //干翻字节！
        //题目要求空间O1，时间On
        //链表题，用c++写有感觉
        //第一个为奇数，第二个为偶数
        //先找到第一个和第二个节点
        //这个题比较简单，十分钟，就这还中等题？
        //一次提交，时间击败-88.79%，空间击败-49.59%
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode * oddNode = head;
        ListNode * evenNode = head->next;
        //保存偶数节点头
        ListNode * evenNodeHead = evenNode;
        //开始串联，一个为空就结束
        while(oddNode && evenNode){
            oddNode->next = evenNode->next;
            oddNode = oddNode->next;
            if(oddNode){
                evenNode->next = oddNode->next;
                evenNode = evenNode->next;
            }
        }
        //连接奇数和偶数链表
        ListNode * temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = evenNodeHead;
        return head;
    }
};
