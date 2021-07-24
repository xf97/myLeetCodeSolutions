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
    bool hasCycle(ListNode *head) {
        //干翻字节！
        //应该用双指针，但是要前进几步我给忘了，双指针的空间复杂度就是O1了
        //用相遇问题吧
        //对了，自己做的，就是用相遇的想法
        //十分钟，两次提交，时间击败-99.79%，空间击败-67.13%
        //边界处理
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        //快慢双指针
        ListNode * slow = head;
        ListNode * fast = head->next;
        //开始冲锋
        while(fast&& fast->next){
            if(fast == slow){
                //相遇
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
