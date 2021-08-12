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
    ListNode* swapPairs(ListNode* head) {
        //好久之前做的了，干翻腾讯CSIG！
        //要保存prev和next
        //当prev->next为空时完蛋
        //用个假头节点就很方便
        //很棒！一次提交，二十五分钟
        //做的完全正确，如果不是交换节点值，而是更改链接，接近一个困难题了
        //自己还是做出来更改链接的版本了
        //边界判断
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        //假头节点出来
        ListNode * fakeHead = new ListNode(0);
        ListNode * prev = fakeHead;
        prev->next = head;
        //要求每段要有两个子节点
        while(prev->next && prev->next->next){
            ListNode * node1 = prev->next;
            ListNode * node2 = node1->next;
            ListNode * next = node2->next;
            //更换链接
            prev->next = node2;
            node2->next = node1;
            node1->next = next;
            //前进
            prev = node1;
            //现在考虑奇数个节点的情况
        }
        return fakeHead->next;
    }   
};
