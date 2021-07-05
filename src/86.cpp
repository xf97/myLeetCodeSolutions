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
    ListNode* partition(ListNode* head, int x) {
        //又到了我最喜欢的中等难度链表指针题了（不是）
        //已经想到了解题思路，两条链表，一条拼大的，一条拼小的，最后组起来
        //学到了，创建新链表要分配节点空间
        //一次提交，十五分钟（主要是链表的一些语法错误），时间击败-16.99%，空间击败-85.80%
        //边界处理
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode * small = new ListNode(0); //要创建节点
        ListNode * smallHead = small; //小链表头
        ListNode * big = new ListNode(0);
        ListNode * bigHead = big; //大链表头
        //遍历链表
        ListNode * ptr = head;
        while(ptr !=  nullptr){
            if(ptr->val < x){
                //添加到小链表末尾
                //只有用next才真正的链入
                small->next  = ptr;
                small = small->next;
            }
            else{
                //添加到大链表末尾
                big->next = ptr;
                big = big->next;
            }
            ptr = ptr->next;;
        }
        //合并
        big->next = nullptr;    //处理尾节点
        small->next = bigHead->next;
        return smallHead->next;
    }
};
