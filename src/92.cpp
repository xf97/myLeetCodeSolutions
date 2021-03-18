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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //又是尝试中等题的一天
        //要是逆置链表太麻烦，能不能只是逆置节点的值
        //题目保证left<=right
        //题目保证left<=right<=n, 即left和right一定在链表内
        //通过, 25分钟
        /*
        时间击败：100%
        空间击败：60.48%
        */
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        else if(left == right){
            return head;
        }
        else{
            stack<int> nodeValue;
            int index = 1;  //遍历位置
            ListNode * pNode = head;
            while(pNode != nullptr && index <= right){
                if(index >= left){
                    nodeValue.push(pNode->val);
                }
                pNode = pNode->next;    //注意边界
                index ++;
            }
            //然后再次遍历
            pNode = head;
            index = 1;
            while(pNode != nullptr && index <= right){
                if(index >= left){
                    //进入反转位置
                    pNode->val = nodeValue.top();
                    nodeValue.pop();
                }
                index ++;
                pNode = pNode->next;
            }
            return head;
        }
    }
};
