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
    ListNode* reverseList(ListNode* head) {
        //后天面试字节，冲呀
        //原地翻转
        //On时间复杂度
        //边界情况
        //十分钟，两次提交，时间击败-95.76%, 空间击败-99.44%
        if(head == nullptr || head->next ==  nullptr){
            return head;
        }
        ListNode * prev = nullptr;  //前一节点
        ListNode * p = head;    //当前翻转节点
        //先拿到尾巴
        while(p->next){
            p =  p->next;
        }
        ListNode * tail = p;
        p = head;
        while(prev != tail){
            ListNode * node = p->next;  //保存下一节点
            //翻转
            p->next = prev;
            //移动
            prev  = p;
            p = node;
        }

        return tail;
    }
};
