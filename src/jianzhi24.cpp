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
    ListNode* reverseList(ListNode* head) {
        //当年腾讯的面试题，现在我来复仇了
        //这种由后向前的，我想用栈
        /*
        nice，一次通过
        时间击败：71.31%
        空间击败：41.77%
        */
        //边界条件
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        else{
            //只在变量应该被声明且能够初始化的时候才声明变量
            stack<ListNode *> nodeStack;
            ListNode * temp = head;
            while(temp != nullptr){
                nodeStack.push(temp);
                temp = temp->next;
            }
            //现在，反转后的头节点出栈
            ListNode * newHead = nodeStack.top();
            temp = newHead;
            nodeStack.pop();
            //现在开始拼接
            while(! nodeStack.empty()){
                temp->next = nodeStack.top();
                temp = temp->next;
                nodeStack.pop();
            }
            temp->next = nullptr;
            return newHead;
        }
    }
};
