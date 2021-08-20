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
    ListNode* sortList(ListNode* head) {
        //干翻字节跳动
        //一种很舔狗的方法是数组排序然后重构链表
        //但是时间空间复杂度分别是Onlogn和On
        //先让我舔起来
        vector<int> nums;
        ListNode * temp = head;
        //边界处理
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        //开始塞
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        //排序
        sort(nums.begin(), nums.end());
        //重构
        ListNode * fakeHead = new ListNode();
        temp = fakeHead;
        for(const int & n : nums){
            ListNode * node = new ListNode(n);
            temp->next = node;
            temp = temp->next;
        }
        return fakeHead->next;
    }
};
