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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        //假设有一个链表，0-1-2-3-4-5-6，倒数第3个是7-3+1=5第五个结点
        //即倒数第k个是n-k+1个，即n - (k - 1)个
        //快慢指针法，快指针先走k - 1个，然后快慢指针一起走，直到快指针到末尾
        //特殊情况，k不在链表内（看链表有没有k个元素），空链表
        //行，想清楚了，开始动手
        //一次通过，时间击败：34.41%，空间击败：94.52%
        //空链表
        if(head == nullptr){
            return head;
        }
        //快指针
        ListNode * pFast = head;
        for(int i = 0; i < (k - 1); i ++){
            //没有k不在链表中
            if(pFast == nullptr){
                return head;
            }
            pFast = pFast->next;
        }
        //慢指针
        ListNode * pSlow = head;
        //pFast不为null，那么pSlow肯定也不为
        while(pFast->next != nullptr){
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pSlow;
    }
};
