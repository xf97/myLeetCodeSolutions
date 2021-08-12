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
    ListNode* rotateRight(ListNode* head, int k) {
        //干翻腾讯CSIG
        //要注意处理旋转超限的情况
        //先要统计链表长度
        //二十分钟，没太细心，三次提交
        //时间击败-31.80%，空间击败-95.08%
        int length = 0;
        ListNode * temp = head;
        //边界处理
        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }
        while(temp){
            length ++;
            temp = temp->next;
        }
        //然后处理k
        k %= length;
        if(k == 0){
            return head;
        }
        //现在k会落在链表内了，开始找截断的地方
        //现在要找倒数第k个节点，最后一个是倒数第1个
        ListNode * fast = head;
        int tempCount = k;
        while(tempCount){
            fast = fast->next;
            tempCount --;
        }
        ListNode * slow = head;
        ListNode * fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode * prev = fakeHead;
        while(fast){
            prev = prev->next;
            slow = slow->next;
            fast = fast->next;
        }
        //开始截断链表
        prev->next = nullptr;
        //尾巴续回去
        temp = slow;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        return slow;
    }
};
