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
    vector<int> reversePrint(ListNode* head) {
        /*
        time defeat: 90.19%
        space defeat: 51.11%
        */
        //学完了第二章了，现在我要开始剑指了 (RNG粉丝专用)
        //不看答案，手写代码
        //到底后又返回，用栈 (还可递归)
        //我还看了effective c++，现在我要在变量值得声明时才声明变量 (避免构造和析构函数)
        vector<int> result; //结果
        //边界条件
        if(head == nullptr){
            return result;
        }
        stack<int> nodeVal; //存储遍历结果的栈
        ListNode * temp = head;
        while(temp != nullptr){
            //cout<<temp->val<<endl;
            nodeVal.push(temp->val);
            temp = temp->next;
        }
        //倒序输出
        while(! nodeVal.empty()){
            result.emplace_back(nodeVal.top());
            nodeVal.pop();
        }
        return result;
    }
};
