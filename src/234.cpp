/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
简化操作-使用数组存储链表的值，然后直接比较，时间空间复杂度都是O(n)
time defeat: 90.82%
space defeat: 7.71%
time consuming: 15 mins
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>  nodeVal;   //用来存储节点值的列表 
        if(head == nullptr){
            //空链表
            return true;
        }
        else if(head->next == nullptr){
            //单个节点，必然是回文
            return true;
        }
        ListNode * nowNode =  head; //遍历指针
        while(nowNode != nullptr){
            nodeVal.emplace_back(nowNode->val); //填充数组
            nowNode = nowNode->next;
        }
        //产生翻转数组
       auto tempArray = nodeVal;   //保存副本
        reverse(nodeVal.begin(), nodeVal.end());    //翻转原值
        if(tempArray == nodeVal){
            return true;
        }
        else{
            return false;
        }
    }
};
