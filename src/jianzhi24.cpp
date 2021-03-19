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
        /*
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
        */
        //现在用循环的方法再做一遍
        //考虑链表1-2-3-4，要同时记录被逆转节点的前后节点
        //然后指针指向前一个结点，再往前挪动
        //处理边界情况
        //时间击败：68.95%，空间击败：90.52%
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        else{
            ListNode * preNode = nullptr;
            ListNode * nowNode = head;
            ListNode * reverseHead = nullptr;
            //要考虑尾节点这个情况
            while(nowNode != nullptr){
                ListNode * nextNode = nowNode->next;
                if(nextNode == nullptr){
                    //原来的尾节点会变成逆转后的头节点
                    reverseHead = nowNode;
                }
                nowNode->next = preNode;
                //向前挪
                preNode = nowNode;
                nowNode = nextNode;
            }
            return reverseHead;
        }
    }
};
