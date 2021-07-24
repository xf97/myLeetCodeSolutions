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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //如果是K个怎么办？合并链表，再生成
        //干翻字节
        //递归，每次用快慢指针找中点，找到以后创建树节点
        //然后左右递归，左边递归的节点赋给左子节点，右边给右节点
        //二十分钟，自己做出来的，出色！
        //中等题，一次提交，时间击败-82.26%，空间击败-88.01%
        //边界处理
        //会有空链表吗
        if(head == nullptr){
            return nullptr;
        }
        else if(head->next == nullptr){
            //只有一个节点
            TreeNode * node = new TreeNode(head->val);
            node->left = nullptr;
            node->right = nullptr;
            return node;
        }
        else{
            //找中点，快慢指针
            ListNode * slowPtr = head;
            ListNode * fastPtr = head;
            while(fastPtr->next && fastPtr->next->next){
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next->next;
            }
            //slowPtr指向中点
            //cout<<slowPtr->val<<" "<<fastPtr->val<<endl;
            //要分割链表
            ListNode * temp = head;
            while(temp != slowPtr && temp->next != slowPtr){
                temp = temp->next;
            }
            //创建节点
            TreeNode * node = new TreeNode(slowPtr->val);
            node->right = sortedListToBST(slowPtr->next);
            //向下递归
            //分割链表
            temp->next = nullptr;
            head = (head == slowPtr) ? nullptr : head;
            node->left = sortedListToBST(head);
            return node;
        }
    }
};
