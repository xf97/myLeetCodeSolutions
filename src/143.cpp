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
private:
    ListNode * reverseList(ListNode * _node){
        ListNode * prev = nullptr;
        ListNode * p = _node;
        while(p->next){
            ListNode * temp = p->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        p->next = prev;
        return p;
    }
public:
    void reorderList(ListNode* head) {
        //开启今日份干翻字节！
        //双指针，从前后逼近中点
        //不行，由后向前比较困难
        //快慢指针，获得链表中点
        //二十五分钟，一次通过，思路完全正确
        //时间击败-76.94%，空间击败-79.81%
        //边界检查
        if(head == nullptr || head->next == nullptr){
            return;
        }
        //获得头尾节点
        ListNode * newHead = head;  //返回的新头
        ListNode * fast = head;
        ListNode * slow = head;
        //fast一次走两步，slow一次走一步，为空时slow指向中点
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //翻转由slow开头的链表段，并返回新的头节点
        ListNode * backHead = reverseList(slow);
        //拼接前后两部分
        //长度相差不过1，直接拼接
        slow = newHead;
        while(slow && backHead){
            ListNode * slowNext = slow->next;
            ListNode * fastNext = backHead->next;
            slow->next = backHead;
            slow = slowNext;
            backHead->next = slowNext;
            backHead = fastNext;
        }
        return;
    }
};
