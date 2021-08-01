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
    ListNode* removeZeroSumSublists(ListNode* head) {
        //干翻蚂蚁金服
        //有个On2的解法
        //不对，我感觉要用栈
        //不对，人脑袋都是晕乎乎的，要用哈希表存储前缀和
        //强强强，这个前缀和很强，你的前缀和和我的前缀和相等，那么说明我们的中间节点为0
        //一次提交，二十分钟，时间击败-99.28%，空间击败-45.90%
        unordered_map<int, ListNode *> preFixSum;
        //假头节点
        ListNode * fakeHead = new ListNode();
        fakeHead->next = head;
        ListNode * temp = fakeHead;
        int currentSum = 0;
        while(temp){
            currentSum += temp->val;
            preFixSum[currentSum] = temp;
            temp = temp->next;
        }
        temp = fakeHead;
        currentSum = 0;
        while(temp){
            currentSum += temp->val;
            //看看有没有相等的，没有的话自己就指向自己
            temp->next = preFixSum[currentSum]->next;
            temp = temp->next;
        }
        return fakeHead->next;
    }
};
