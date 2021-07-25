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
    void reverseSubList(ListNode* _left, ListNode * _right){
        ListNode * prev = nullptr;
        ListNode * p = _left;
        while(prev != _right){
            ListNode * temp = p->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        return;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //干翻字节和拼多多
        //做中等题逐渐熟悉起来
        //题目保证left和right一定在链表内
        //难点在于把反转后的子链表拼接回来
        //十分钟，一次提交，时间击败-100%，空间击败-26.72%
        //边界处理
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        //寻找left和right节点，包含right节点
        //要记录前序节点，用假头节点
        ListNode * fakeHead = new ListNode();
        fakeHead->next = head;
        ListNode * prev = fakeHead;
        ListNode * leftNode = head;
        for(int i = 1; i < left && leftNode != nullptr; ++ i){
            leftNode = leftNode->next;
            prev = prev->next;
        }
        ListNode * rightNode = head;
        for(int i = 1; i < right && rightNode != nullptr; ++ i){
            rightNode = rightNode->next;
        }
        ListNode * next = rightNode->next;
        //翻转left和right之内的链表
        reverseSubList(leftNode, rightNode);
        //把子链表接回来
        prev->next = rightNode;
        leftNode->next = next;
        return fakeHead->next;
    }
};
