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
    void reverseAGroup(ListNode *  _head,  ListNode * _tail){
        ListNode * prev  =  _tail->next;    
        ListNode * p = _head;
        while(prev != _tail){
            ListNode * next =  p->next;
            p->next = prev;
            prev = p;
            p =next;
        }
        return;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //基本上看懂解法了
        //干翻字节！
        //自己做出来了，nice，理解了
        //一次提交，时间击败-59.04%，空间击败-46.61%
        //原地翻转
        ListNode * hair = new ListNode(0);  //假头结点
        hair->next = head;
        ListNode * prev = hair; //翻转时的前节点
        //开始翻转
        while(head){
            ListNode * tail = prev; //k个一组，就不包含尾部节点
            for(int i = 0; i < k;  i++){
                tail = tail->next;
                if(tail == nullptr){
                    //空了，那就不翻了
                    return hair->next;
                }
            }
            //先保存下一个节点
            ListNode * next = tail->next;
            //得到头尾节点值，现在翻转
            //pair<ListNode  *, ListNode *> newHeadAndTail = 
            reverseAGroup(head,  tail);
             //把头尾接回来
            head->next = next;
            prev->next =  tail;
            //移动
            prev  = head;
            head = next;
            }
        return hair->next;
    }
};
