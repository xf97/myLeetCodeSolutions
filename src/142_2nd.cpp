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
    ListNode *detectCycle(ListNode *head) {
        //干翻字节，这道题如果不按照进阶要求的话，使用On空间很容易做
        //快慢指针，记录相遇时两者走的距离，相减就能得到环的大小
        //绝了，数学推导，我会了
        //O1空间冲他
        //十五分钟，O1空间复杂度完成
        //两次提交，时间击败-88.82%，空间击败-42.73%
        //边界处理
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        ListNode * slow = head;
        ListNode * fast = head;
        //相遇时，找到环
        ListNode * meetPoint = nullptr; //相遇点
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                //找到相遇，打破循环。有循环一定相遇
                meetPoint = slow;
                break;
            }
        }
        if(fast->next == nullptr || fast->next->next == nullptr){
            //无环
            return meetPoint;
        }
        //起始节点
        ListNode * temp = head;
        //temp和meetPoint终会相遇，相遇点就是入环点
        while(temp != meetPoint){
            temp = temp->next;
            meetPoint = meetPoint->next;
        }
        return meetPoint;
    }
};
