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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //干翻阿里巴巴
        //两个指针，一个落后另一个n个，当另一个到末尾时，就可以删除了
        //一次扫描结束
        //处理边界情况
        //十分钟，一次提交，卧槽，新冠就在我身边
        //时间击败-100%，空间击败-76.83%
        ListNode * fast = head;
        while(n-- && fast != nullptr){
            fast = fast->next;
        }
        //如果fast为空，则n肯定是第一个节点，返回
        if(fast == nullptr){
            ListNode * result = head->next;
            delete head;
            return result;
        }
        ListNode * prev = head;
        while(fast->next != nullptr){
            fast = fast->next;
            prev = prev->next;
        }
        //到达末尾
        ListNode * target = prev->next;
        //删除
        prev->next = target->next;
        delete target;
        return head;
    }
};
